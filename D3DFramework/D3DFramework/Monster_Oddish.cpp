#include "stdafx.h"
#include "Monster_Oddish.h"
//#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Oddish::Monster_Oddish()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	anim->SetLoop(true);

	
	//anim->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	//transform->RotateY(90);
	offsetY = 1.f;
	Speed = 0.3f;
	state = State::END;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Monster_Oddish::~Monster_Oddish()
{
}

void Monster_Oddish::Update()
{
	Parttern();
	Monster::Update();

}

void Monster_Oddish::Render()
{
	Monster::Render();
}

void Monster_Oddish::Parttern()
{

	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;



	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);




	if (state != State::PLAYER_SEARCH && Dist < 5.f) {
		state = State::PLAYER_SEARCH;
		//�̰����� �÷��̾� ���ϴ� ���⺤�� �����ְ�

	}
	else if (state == State::END) { // �̰� �������� ������ ������
		state = (State)Random::Range(0, 0); // ���� �������ִ°� (����)

		if (state == State::WALK) {            // �̰����� ���� ����
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}
	}
	else if (state == State::WALK) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}
	else if (state == State::PLAYER_SEARCH) {
		if (Dist >= 5.f) {
			state = State::END;
			Time[0] = 0;
			Frame[0] = 0;
			return;
		}
		direction = PlayerT->position - transform->position;
		D3DXVec3Normalize(&direction, &direction);
		transform->position.x += direction.x * 6.f * Speed * TimeManager::DeltaTime();
		transform->position.z += direction.z * 6.f * Speed * TimeManager::DeltaTime();
	}

}

void Monster_Oddish::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * Speed * TimeManager::DeltaTime();
	transform->position.z += direction.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::END;
		}
	}
}

void Monster_Oddish::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		anim->SetDelay(0.2f);
		Time[0] = 0.f;
		state = State::END;
		
	}
}

