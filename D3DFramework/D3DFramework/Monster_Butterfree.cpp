#include "stdafx.h"
#include "Monster_Butterfree.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Butterfree::Monster_Butterfree()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	TextureAttack = TextureKey::BUTTER_ATTACK_D_01;
	TextureWALK = TextureKey::BUTTER_WALK_D_01;
	ani->SetLoop(true);

	SetSpriteWalk();
	//ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	//transform->RotateY(90);
	offsetY = 2.5f;
	Speed = 1.f;
	CurrentStatus = Status::END;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
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

	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;



	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);




	if (CurrentStatus != Status::PLAYER_SEARCH && Dist < 5.f) {
		CurrentStatus = Status::PLAYER_SEARCH;
		//이곳에서 플레이어 향하는 방향벡터 정해주고
		//MoveDir = PlayerT->position - transform->position;
		MoveDir.x = 1;
		MoveDir.y = 0;
		MoveDir.z = 1;
		D3DXVec3Normalize(&MoveDir, &MoveDir);
		MoveDir *= 1.5f;
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		b->SetDir(MoveDir.x, MoveDir.z, MoveDir.y);
		*(b->transform) = *transform;

		SetSpriteAttack();
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (CurrentStatus == Status::END) { // 이건 랜덤패턴 갖기전 대기상태
		CurrentStatus = (Status)Random::Range(0, 1); // 패턴 나누어주는곳 (랜덤)

		if (CurrentStatus == Status::MOVE) {            // 이곳에서 패턴 레디
			MoveDir.x = -4.f + Random::Value(9) * 1.f;
			MoveDir.z = -4.f + Random::Value(9) * 1.f;
		}
		else if (CurrentStatus == Status::ATTACK) {            // 이곳에서 패턴 레디
			MoveDir.x = -4.f + Random::Value(9) * 1.f;
			MoveDir.z = -4.f + Random::Value(9) * 1.f;
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			b->SetDir(MoveDir.x, MoveDir.z);
			*(b->transform) = *transform;
			/*b->transform->position.y += 0.5f;*/
			SetSpriteAttack();
		}
	}
	else if (CurrentStatus == Status::MOVE) {		//// 이곳부터 업데이트
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

	transform->position.x += MoveDir.x * Speed * TimeManager::DeltaTime();
	transform->position.z += MoveDir.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4번의 파닥거림 후
			Frame[0] = 0;
			CurrentStatus = Status::END;
		}
	}
}

void Monster_Butterfree::Attack()
{
	Time[0] += TimeManager::DeltaTime();
	if (Time[0] >= 0.6f) {
		ani->SetDelay(0.2f);
		Time[0] = 0.f;
		CurrentStatus = Status::END;
		SetSpriteWalk();
	}
}

