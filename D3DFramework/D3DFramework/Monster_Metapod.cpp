#include "stdafx.h"
#include "Monster_Metapod.h"
#include "Rectangle.h"

Monster_Metapod::Monster_Metapod()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	TextureAttack = TextureKey::META_ATTACK_D_01;
	TextureWALK = TextureKey::META_WALK_D_01;
	anim->SetLoop(true);

	SetSpriteWalk();
	offsetY = 1.f;
	//Speed = 0.15f;
	state = State::END;
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
	if (state == State::END) { // 이건 랜덤패턴 갖기전 대기상태
		state = (State)Random::Range(0, 0); // 패턴 나누어주는곳 (랜덤)

		if (state == State::WALK) {            // 이곳에서 패턴 레디
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}
		
	}
	else if (state == State::WALK) {		//// 이곳부터 업데이트
		RandomMovePattern();
	}

}

void Monster_Metapod::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	//transform->position.x += direction.x * Speed * TimeManager::DeltaTime();
	//transform->position.z += direction.z * Speed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 3) {			// 3번의 파닥거림 후
			Frame[0] = 0;
			state = State::END;
		}
	}
}


