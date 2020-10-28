#include "stdafx.h"
#include "Monster_Vileplume.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Monster_Vileplume::Monster_Vileplume()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	
	anim->SetLoop(true);

	offsetY = 1.f;
	Speed = 0.5f;
	state = State::END;
	AttackDelay = false;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Monster_Vileplume::~Monster_Vileplume()
{
}

void Monster_Vileplume::Update()
{
	Parttern();
	Monster::Update();
}

void Monster_Vileplume::Render()
{
	Monster::Render();
}

void Monster_Vileplume::Parttern()
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);



	if (state == State::END && Dist < 8.f) {
		state = State::PLAYER_SEARCH;
		

		
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::END) { // 이건 랜덤패턴 갖기전 대기상태
		state = (State)Random::Range(0, 0); // 패턴 나누어주는곳 (랜덤)

		if (state == State::WALK) {            // 이곳에서 패턴 레디
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}
	}
	else if (state == State::WALK) {		//// 이곳부터 업데이트
		RandomMovePattern();
	}
	else if (state == State::PLAYER_SEARCH) {
		Attack(PlayerT);
	}
}

void Monster_Vileplume::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * Speed * TimeManager::DeltaTime();
	transform->position.z += direction.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 2) {			// 4번의 파닥거림 후
			Frame[0] = 0;
			state = State::END;
		}
	}
}

void Monster_Vileplume::Attack(Transform* PlayerT)
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

void Monster_Vileplume::CreateBullet(Transform* PlayerT) {
	direction = PlayerT->position - transform->position;
	//MoveDir *= 1.5f;
	float R = 0.5f;
	if (direction.x > direction.z) {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		Dir2.z -= R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
		b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Dir2 = direction;
		Dir2.z += R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
	}
	else {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		Dir2.x -= R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
		b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Dir2 = direction;
		Dir2.x += R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
	}
}