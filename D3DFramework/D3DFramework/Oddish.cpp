#include "stdafx.h"
#include "Oddish.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Oddish::Oddish()
{
	SetTexture(State::WALK, TextureKey::ODDI_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::ODDI_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::ODDI_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::ODDI_WALK_D_01, 3, 1);

	anim->SetLoop(true);
	UpdateAnimation();

	moveSpeed = 2.5f;
	state = State::READY;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Oddish::~Oddish()
{
}

void Oddish::Update()
{
	Pattern();
	Monster::Update();

}

void Oddish::Render()
{
	Monster::Render();
}

void Oddish::Pattern()
{
	/////////////////////////////////////////////////////////// 플레이어 탐지
	PlayerSearch(6.f, 10.f);


	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
	if (isSearch) {

		if (state == State::READY) { // 이건 랜덤패턴 갖기전 대기상태
			state = (State)Random::Range(1, 1); // 패턴 나누어주는곳 (랜덤)

			if (state == State::WALK) {            // 이곳에서 패턴 레디
				// 이동 Ready
			}
			else if (state == State::ATTACK) {
				// 공격 Ready
			}
		}

		/////////////////////////////////////////////////////////// 패턴 Update
		if (state == State::WALK) {
			MovePlayerFollow();
		}
		else if (state == State::ATTACK) {
			// 공격 Update
		}

	}



	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
	else {

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
		else if (state == State::ATTACK) {
			// 공격 Update
		}
	}


}


