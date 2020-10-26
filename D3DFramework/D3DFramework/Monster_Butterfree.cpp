#include "stdafx.h"
#include "Monster_Butterfree.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "CubeMan.h"

Monster_Butterfree::Monster_Butterfree()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	//ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	ani->SetSprite(TextureKey::BUTTER_WALK_L_01, TextureKey::BUTTER_WALK_L_03);
	ani->SetLoop(true);
	ani->SetDelay(0.2f);
	//transform->RotateY(90);
	floating = 2.5f;
	CurrentStatus = Status::END;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Monster_Butterfree::~Monster_Butterfree()
{
}

void Monster_Butterfree::Update()
{
	ButterfreeParttern();
	SetTextureAngle();
	Monster::Update();

}

void Monster_Butterfree::Render()
{
	Monster::Render();
}

void Monster_Butterfree::ButterfreeParttern()
{

	GameObject* g = ObjectManager::GetInstance()->FindObject<CubeMan>();
	Transform* PlayerT = g->transform;

	

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX*distX + distZ + distZ);

	


	if (CurrentStatus != Status::PLAYER_SEARCH && Dist < 5.f) {
		CurrentStatus = Status::PLAYER_SEARCH;
		//�̰����� �÷��̾� ���ϴ� ���⺤�� �����ְ�
		MoveDir = PlayerT->position - transform->position;
		D3DXVec3Normalize(&MoveDir, &MoveDir);
		MoveDir *= 0.05f;
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		b->SetDir(MoveDir.x, MoveDir.z, MoveDir.y);
		*(b->transform) = *transform;

		ani->SetSprite(TextureKey::BUTTER_ATTACK_L_01, TextureKey::BUTTER_ATTACK_L_02);
		ani->SetDelay(0.3f);
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (CurrentStatus == Status::END) { // �̰� �������� ������ ������
		CurrentStatus = (Status)Random::Range(0, 1); // ���� �������ִ°� (����)

		if (CurrentStatus == Status::MOVE) {            // �̰����� ���� ����
			MoveDir.x = -4.f + Random::Value(9) * 1.f;
			MoveDir.z = -4.f + Random::Value(9) * 1.f;
		}
		else if (CurrentStatus == Status::ATTACK) {            // �̰����� ���� ����
			MoveDir.x = -4.f + Random::Value(9) * 1.f;
			MoveDir.z = -4.f + Random::Value(9) * 1.f;
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			b->SetDir(MoveDir.x, MoveDir.z);
			*(b->transform) = *transform;
			/*b->transform->position.y += 0.5f;*/
			ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
			ani->SetDelay(0.3f);
		}
	}
	else if (CurrentStatus == Status::MOVE) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}
	else if (CurrentStatus == Status::ATTACK) {
		Attack();
	}
	else if (CurrentStatus == Status::PLAYER_SEARCH) {
		Attack();
	}

}

void Monster_Butterfree::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();
	
	transform->position.x += MoveDir.x * TimeManager::DeltaTime();
	transform->position.z += MoveDir.z * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 5) {			// 5���� �ĴڰŸ� ��
			Frame[0] = 0;
			CurrentStatus = Status::END;
		}
	}
}

void Monster_Butterfree::SetTextureAngle()
{
	Vector3 vLook = Camera::GetInstance()->transform->look;
	Vector3::Normalize(&vLook);

	
	float Angle = Vector3::Angle(MoveDir, vLook);
	
	if (Angle < 100)
		int i = 0;

}

void Monster_Butterfree::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		ani->SetSprite(TextureKey::BUTTER_WALK_D_01, TextureKey::BUTTER_WALK_D_03);
		ani->SetDelay(0.2f);
		Time[0] = 0.f;
		CurrentStatus = Status::END;
	}
}