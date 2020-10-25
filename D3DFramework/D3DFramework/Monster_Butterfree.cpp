#include "stdafx.h"
#include "Monster_Butterfree.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"

Monster_Butterfree::Monster_Butterfree()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	//ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	ani->SetSprite(TextureKey::BUTTER_WALK_D_01, TextureKey::BUTTER_WALK_D_03);
	ani->SetLoop(true);
	ani->SetDelay(0.2f);

	floating = 2.5f;
	CurrentStatus = Status::END;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Monster_Butterfree::~Monster_Butterfree()
{
}

void Monster_Butterfree::Update()
{
	if (CurrentStatus == Status::END) { // 이건 랜덤패턴 갖기전 대기상태
		CurrentStatus = (Status)Random::Range(0,1); // 패턴 나누어주는곳 (랜덤)

		if (CurrentStatus == Status::MOVE) {            // 이곳에서 패턴 레디
			MoveDir.x = -0.015f + Random::Value(8) * 0.01f;
			MoveDir.z = -0.015f + Random::Value(8) * 0.01f;
		}
		else if (CurrentStatus == Status::ATTACK) {            // 이곳에서 패턴 레디
			MoveDir.x = -0.015f + Random::Value(8) * 0.01f;
			MoveDir.z = -0.015f + Random::Value(8) * 0.01f;
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			b->SetDir(MoveDir.x, MoveDir.z);
			*(b->transform) = *transform;
			b->transform->position.y += 0.5f;
			ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
			ani->SetDelay(0.3f);
		}
	}
	else if (CurrentStatus == Status::MOVE) {
		RandomMovePattern();
	}
	else if (CurrentStatus == Status::ATTACK) {
		Attack();
	}


	Monster::Update();
}

void Monster_Butterfree::Render()
{
	Monster::Render();
}

void Monster_Butterfree::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();
	transform->position.x += MoveDir.x;
	transform->position.z += MoveDir.z;

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 5) {			// 5번의 파닥거림 후
			Frame[0] = 0;
			CurrentStatus = Status::END;
		}
	}
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