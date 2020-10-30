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
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
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
	if (state == State::READY) { // �̰� �������� ������ ������
		state = (State)Random::Range(1, 1); // ���� �������ִ°� (����)

		if (state == State::WALK) {            // �̰����� ���� ����
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.y = 0.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			direction.Normalized();
		}

	}
	else if (state == State::WALK) {		//// �̰����� ������Ʈ
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
		if (Frame[0] == 3) {			// 3���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::READY;
		}
	}
}


