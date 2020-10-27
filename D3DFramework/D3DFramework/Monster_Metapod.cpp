#include "stdafx.h"
#include "Monster_Metapod.h"
#include "Rectangle.h"

Monster_Metapod::Monster_Metapod()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	TextureAttack = TextureKey::META_ATTACK_D_01;
	TextureWALK = TextureKey::META_WALK_D_01;
	ani->SetLoop(true);

	SetSpriteWalk();
	offsetY = 1.f;
	Speed = 0.15f;
	CurrentStatus = Status::END;
	Monster::Update();
}


Monster_Metapod::~Monster_Metapod()
{
}

void Monster_Metapod::Update()
{
	Pattern();
	SetTextureAngle();
	Monster::Update();
}

void Monster_Metapod::Render()
{
	Monster::Render();
}

void Monster_Metapod::Pattern() {
	if (CurrentStatus == Status::END) { // �̰� �������� ������ ������
		CurrentStatus = (Status)Random::Range(0, 0); // ���� �������ִ°� (����)

		if (CurrentStatus == Status::MOVE) {            // �̰����� ���� ����
			MoveDir.x = -4.f + Random::Value(9) * 1.f;
			MoveDir.z = -4.f + Random::Value(9) * 1.f;
		}
		
	}
	else if (CurrentStatus == Status::MOVE) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}

}

void Monster_Metapod::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += MoveDir.x * Speed * TimeManager::DeltaTime();
	transform->position.z += MoveDir.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 3) {			// 3���� �ĴڰŸ� ��
			Frame[0] = 0;
			CurrentStatus = Status::END;
		}
	}
}


