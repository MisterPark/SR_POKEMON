#include "stdafx.h"
#include "Scyther.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Bullet_Tornado.h"
#include "Player.h"

Scyther::Scyther()
{
	name = L"스라크";
	SetTexture(State::WALK, TextureKey::SCY_WALK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SCY_WALK_D_01, 3, 1);

	anim->SetLoop(true);
	UpdateAnimation();

	offsetY = 1.5f;
	moveSpeed = 3.f;
	state = State::READY;
	transform->scale *= 1.5f;
	Monster::Update(); // 몬스터 생성하자마자 총알쏘면 위치값 0이라 총알이 비교적 내려가는거 방지
}

Scyther::~Scyther()
{
}

void Scyther::Update()
{
	Parttern();
	Monster::Update();

}

void Scyther::Render()
{
	Monster::Render();
}

void Scyther::Parttern()
{
	/////////////////////////////////////////////////////////// 플레이어 탐지
	PlayerSearch(10.f, 20.f);


	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
	if (isSearch) {

		/////////////////////////////////////////////////////////// 패턴 Ready
		if (state == State::READY) {
			//state = (State)Random::Range(1, 1);
			if (disPlayer > 7.f && disPlayer < 20.f) {
				state = State::SKILL;
			}
			else if (disPlayer <= 7.f) {
				if(Frame[2] == 1)
					state = State::WALK;
				else if(Frame[2] == 0)
					state = State::SKILL2;
			}

			if (state == State::WALK) {
				anim->SetDelay(0.2f);
			}
			else if (state == State::SKILL) {
				anim->SetDelay(1.5f);
			}
			else if (state == State::SKILL2) {
				anim->SetDelay(1.f);
			}
			
		}

		/////////////////////////////////////////////////////////// 패턴 Update
		if (state == State::WALK) {
			MovePlayerFollow();
			if (Frame[2] == 1) { //토네이도 공격 쿨타임 여부
				Time[1] += TimeManager::DeltaTime();
				if (Time[1] > 2.5f) {
					Time[1] = 0.f;
					Frame[2] = 0;
					state = State::READY;
				}
			}
		}
		else if (state == State::SKILL) {
			Time[1] += TimeManager::DeltaTime();
			if (1.5f < Time[1]) {
				MovePlayerFollow(15.f);
				if (1.65f < Time[1]) {
					state = State::READY;
					Time[1] = 0;
					anim->SetDelay(0.2f);
					SkillBullet();
					return;
				}
			}
		}
		else if (state == State::SKILL2) {
			Time[1] += TimeManager::DeltaTime();
			if (Time[1] > 0.8f) {
				Time[1] = 0;
				Frame[1]++;
				if (Frame[1] == 1) {
					Skill2Bullet();
				}
				else if (Frame[1] == 2) {
					state = State::READY;
					anim->SetDelay(0.2f);
					Frame[1] = 0;
					Frame[2]++;
				}
			}
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
			
		}

		/////////////////////////////////////////////////////////// 패턴 Update
		if (state == State::WALK) {
			//1.5f 시간동안 걷고 총 3번 반복
			MoveRandomPattern(1.5f, 1);
		}
	}


}

void Scyther::SkillBullet()
{
	for (int j = -2; j < 3; j++)
	{
		for (int i = -2; i < 3; i++)
		{
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			Vector3 Dir2 = { direction.x + j * 0.8f, 0.f, direction.z + i * 0.8f };
			Dir2.Normalized();
			b->SetDir(Dir2);
			*(b->transform) = *transform;
			b->transform->position.y -= 1.f;
			b->transform->scale.x = 0.7f;
			b->transform->scale.y = 0.7f;
			b->transform->scale.z = 0.7f;
			//b->moveSpeed = 0.5f;
		}
	}
}

void Scyther::Skill2Bullet()
{
	Bullet_Tornado* b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Vector3 Dir2 = { -1.f, 0.f, 1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	*b->transform = *transform;

	b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, 1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	//b->transform->position.y -= 1.f;

	b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { -1.f, 0.f, -1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	//b->transform->position.y -= 1.f;

	b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, -1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	//b->transform->position.y -= 1.f;
	
}

