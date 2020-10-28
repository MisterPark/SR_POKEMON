#include "stdafx.h"
#include "Monster_Caterpie.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Caterpie::Monster_Caterpie()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	//anim->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	anim->SetSprite(TextureKey::CATER_WALK_D_01, TextureKey::CATER_WALK_D_03);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);
	//transform->RotateY(90);
	offsetY = 1.f;
	state = State::END;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Monster_Caterpie::~Monster_Caterpie()
{
}

void Monster_Caterpie::Update()
{
	//�躤��(z)
	direction = transform->look;

	Vector3::Normalize(&direction);

	

	transform->position.x += 0.1;

	/*MoveDir = D3DXToRadian(60);*/
	Monster::Update();

}

void Monster_Caterpie::Render()
{
	Monster::Render();
}



void Monster_Caterpie::Pattern()
{

	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;



	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);


	float radian1 = PlayerT->scale.x / 2;
	float radian2 = transform->scale.x / 2;


	if (state != State::PLAYER_SEARCH && Dist < radian1 + radian2 + 5.f) {
		state = State::PLAYER_SEARCH;
		//�̰����� �÷��̾� ���ϴ� ���⺤�� �����ְ�
		//MoveDir = PlayerT->position - transform->position;
		direction.x = 1;
		direction.y = 0;
		direction.z = 1;
		D3DXVec3Normalize(&direction, &direction);

		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		b->SetDir(direction.x, direction.z, direction.y);
		*(b->transform) = *transform;

		
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::IDLE) { // �̰� �������� ������ ������
		state = (State)Random::Range(0, 1); // ���� �������ִ°� (����)

		if (state == State::WALK) {            // �̰����� ���� ����
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}
		else if (state == State::ATTACK) {            // �̰����� ���� ����
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			b->SetDir(direction.x, direction.z);
			*(b->transform) = *transform;
			/*b->transform->position.y += 0.5f;*/
			
		}
	}
	else if (state == State::WALK) {		//// �̰����� ������Ʈ
		MovePattern();
	}
	else if (state == State::ATTACK) {
		Attack();
	}
	else if (state == State::PLAYER_SEARCH) {
		Attack();
	}

}

void Monster_Caterpie::MovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * Speed * TimeManager::DeltaTime();
	transform->position.z += direction.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::IDLE;
		}
	}
}

void Monster_Caterpie::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		anim->SetDelay(0.2f);
		Time[0] = 0.f;
		state = State::IDLE;
		
	}
}



