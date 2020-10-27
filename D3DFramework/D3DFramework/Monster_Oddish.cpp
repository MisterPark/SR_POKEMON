#include "stdafx.h"
#include "Monster_Oddish.h"
//#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Oddish::Monster_Oddish()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	TextureAttack = TextureKey::ODDI_ATTACK_D_01;
	TextureWALK = TextureKey::ODDI_WALK_D_01;
	ani->SetLoop(true);

	SetSpriteWalk();
	//ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	//transform->RotateY(90);
	offsetY = 1.f;
	Speed = 0.3f;
	CurrentStatus = Status::END;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Monster_Oddish::~Monster_Oddish()
{
}

void Monster_Oddish::Update()
{
	Parttern();
	SetTextureAngle();
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




	if (CurrentStatus != Status::PLAYER_SEARCH && Dist < 5.f) {
		CurrentStatus = Status::PLAYER_SEARCH;
		//�̰����� �÷��̾� ���ϴ� ���⺤�� �����ְ�

	}
	else if (CurrentStatus == Status::END) { // �̰� �������� ������ ������
		CurrentStatus = (Status)Random::Range(0, 0); // ���� �������ִ°� (����)

		if (CurrentStatus == Status::MOVE) {            // �̰����� ���� ����
			MoveDir.x = -4.f + Random::Value(9) * 1.f;
			MoveDir.z = -4.f + Random::Value(9) * 1.f;
		}
	}
	else if (CurrentStatus == Status::MOVE) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}
	else if (CurrentStatus == Status::PLAYER_SEARCH) {
		if (Dist >= 5.f) {
			CurrentStatus = Status::END;
			Time[0] = 0;
			Frame[0] = 0;
			return;
		}
		MoveDir = PlayerT->position - transform->position;
		D3DXVec3Normalize(&MoveDir, &MoveDir);
		transform->position.x += MoveDir.x * 6.f * Speed * TimeManager::DeltaTime();
		transform->position.z += MoveDir.z * 6.f * Speed * TimeManager::DeltaTime();
	}

}

void Monster_Oddish::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += MoveDir.x * Speed * TimeManager::DeltaTime();
	transform->position.z += MoveDir.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			CurrentStatus = Status::END;
		}
	}
}

void Monster_Oddish::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		ani->SetDelay(0.2f);
		Time[0] = 0.f;
		CurrentStatus = Status::END;
		SetSpriteWalk();
	}
}

