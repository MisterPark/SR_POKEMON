#include "stdafx.h"
#include "Metapod.h"
#include "Rectangle.h"

Metapod::Metapod()
{
	SetTexture(State::WALK, TextureKey::META_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::META_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::META_WALK_D_01, 3);
	for (int i = 0; i < 8; i++)
	{
		endArray[(int)State::IDLE][(int)Direction::D + i] = (TextureKey)((int)endArray[(int)State::IDLE][(int)Direction::D + i] - 1);
	}
	anim->SetLoop(true);

	moveSpeed = 0.15f;
	state = State::IDLE;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}


Metapod::~Metapod()
{
}

void Metapod::Update()
{
	Pattern();
	Monster::Update();
}

void Metapod::Render()
{
	Monster::Render();
}

void Metapod::Pattern() {
	if (state == State::IDLE) { // 이건 랜덤패턴 갖기전 대기상태
		state = (State)Random::Range(1, 1); // 패턴 나누어주는곳 (랜덤)

		if (state == State::WALK) {            // 이곳에서 패턴 레디
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}

	}
	else if (state == State::WALK) {		//// 이곳부터 업데이트
		RandomMovePattern();
	}

}

void Metapod::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 3) {			// 3번의 파닥거림 후
			Frame[0] = 0;
			state = State::IDLE;
		}
	}
}


