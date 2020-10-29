#include "stdafx.h"
#include "Oddish.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Oddish::Oddish()
{
	SetTexture(State::WALK, TextureKey::ODDI_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::ODDI_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::ODDI_WALK_D_01, 3);
	for (int i = 0; i < 8; i++)
	{
		endArray[(int)State::IDLE][(int)Direction::D + i] = (TextureKey)((int)endArray[(int)State::IDLE][(int)Direction::D + i] - 1);
	}
	anim->SetLoop(true);

	moveSpeed = 3.f;
	state = State::IDLE;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Oddish::~Oddish()
{
}

void Oddish::Update()
{
	Parttern();
	Monster::Update();

}

void Oddish::Render()
{
	Monster::Render();
}

void Oddish::Parttern()
{

	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	Transform* PlayerT = g->transform;



	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);


	if (state != State::PLAYER_SEARCH && Dist < 6.f) {
		state = State::PLAYER_SEARCH;
		//이곳에서 플레이어 향하는 방향벡터 정해주고
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::IDLE) { // 이건 랜덤패턴 갖기전 대기상태
		state = (State)Random::Range(1, 1); // 패턴 나누어주는곳 (랜덤)

		if (state == State::WALK) {            // 이곳에서 패턴 레디
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.y = 0.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			direction.Normalize(&direction);
		}
	}
	else if (state == State::WALK) {		//// 이곳부터 업데이트
		RandomMovePattern();
	}
	else if (state == State::PLAYER_SEARCH) {
		if (Dist >= 7.f) {
			state = State::IDLE;
			Time[0] = 0;
			Frame[0] = 0;
			return;
		}
		direction = PlayerT->position - transform->position;
		D3DXVec3Normalize(&direction, &direction);
		transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
		transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();
	}

}

void Oddish::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4번의 파닥거림 후
			Frame[0] = 0;
			state = State::IDLE;
		}
	}
}


