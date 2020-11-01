#include "stdafx.h"
#include "Golduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Golduck::Golduck()
{
	name = L"골덕";
	SetTexture(State::WALK, TextureKey::GOLD_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::GOLD_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::GOLD_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::GOLD_WALK_D_01, 3, 1);

	transform->position.x = 10.f;
	anim->SetLoop(true);
	UpdateAnimation();

	offsetY = 1.f;
	state = State::READY;
	moveSpeed = 0.5f;
	Character::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Golduck::~Golduck()
{
}

void Golduck::Update()
{
	//Pattern();
	Character::Update();
}

void Golduck::Render()
{
	Character::Render();
}

/*
void Golduck::Pattern()
{
	GameObject* g = Player::GetInstance()->GetCharacter();
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);


	float radian1 = PlayerT->scale.x / 2;
	float radian2 = transform->scale.x / 2;

	if (!isSearch)
	{
		if (Dist < 5.f) {
			isSearch = true;
			state = State::READY;
		}

		else if (state == State::READY)
		{
			state = State::WALK;
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.y = 0.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			direction.Normalize(&direction);
		}
		if (state == State::WALK) {		//// 이곳부터 업데이트
			RandomMovePattern();
		}
	}

	if (isSearch)
	{
		if (Dist > 10.f)
		{
			isSearch = false;
			Frame[0] = 0;
			state = State::READY;
		}

		else if (state == State::READY && Dist < 3.f)
		{
			state = State::ATTACK;

		}
		else if (state == State::READY && Dist >= 3.f)
		{
			Vector3 Dist = PlayerT->position - transform->position;
			direction = Dist.Normalized();
			state = State::WALK;
			Frame[0] = 0;
		}

		if (state == State::WALK) {		//// 이곳부터 업데이트
			Time[0] += TimeManager::DeltaTime();
			float moveX = direction.x * moveSpeed * TimeManager::DeltaTime();
			float moveZ = direction.z * moveSpeed * TimeManager::DeltaTime();

			if (moveX > 0.05f)
			{
				moveX = 0.05f;
			}
			if (moveZ > 0.05f)
			{
				moveZ = 0.05f;
			}

			transform->position.x += moveX;
			transform->position.z += moveZ;
			if (Time[0] >= 1.5f) {
				Frame[0] ++;
				Time[0] = 0;
				if (Frame[0] == 2) {			// 4번의 파닥거림 후
					Frame[0] = 0;
					state = State::ATTACK;
				}
			}
		}
		if (state == State::ATTACK)
		{
			Attack(PlayerT);
		}
	}
}

void Golduck::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4번의 파닥거림 후
			Frame[0] = 0;
			state = State::END;
		}
	}
}

void Golduck::Attack(Transform* PlayerT)
{
	Time[0] += TimeManager::DeltaTime();
	if (!AttackDelay && Time[0] >= 0.3f) {
		AttackDelay = true;
		CreateBullet(PlayerT);
	}
	if (Time[0] >= 0.6f) {
		Time[0] = 0.f;
		Frame[0]++;
		AttackDelay = false;
		if (Frame[0] == 3) {
			Frame[0] = 0;
			anim->SetDelay(0.2f);
			state = State::WALK;
		}
	}
}

void Golduck::CreateBullet(Transform* PlayerT)
{
	direction = PlayerT->position - transform->position;
	//MoveDir *= 1.5f;
	float R = 0.5f;
	if (direction.x > direction.z) {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Vector3{ Dir2.x, Dir2.y, Dir2.z });
		*(b->transform) = *transform;
		b->isAlliance = false;
	}
	else {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Vector3{ Dir2.x, Dir2.y, Dir2.z });
		*(b->transform) = *transform;
		b->isAlliance = false;
	}
}

*/