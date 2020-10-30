#include "stdafx.h"
#include "Metapod.h"
#include "Rectangle.h"

Metapod::Metapod()
{
	SetTexture(State::WALK, TextureKey::META_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::META_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::META_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::META_WALK_D_01, 3, 1);

	UpdateAnimation();
	anim->SetLoop(true);

	moveSpeed = 1.5f;
	state = State::READY;
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
	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE

	/////////////////////////////////////////////////////////// 패턴 Ready
	if (state == State::READY) {
		state = (State)Random::Range(1, 1);

		if (state == State::WALK) {
			// 이동 Ready
		}
		else if (state == State::ATTACK) {
			// 공격 Ready
		}
	}

	/////////////////////////////////////////////////////////// 패턴 Update
	if (state == State::WALK) {
		//1.5f 시간동안 걷고 총 3번 반복
		MoveRandomPattern(1.5f, 3);
	}

}


