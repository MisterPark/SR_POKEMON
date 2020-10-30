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
	/////////////////////////////////////////////////////////// �÷��̾� Ž�� FALSE

	/////////////////////////////////////////////////////////// ���� Ready
	if (state == State::READY) {
		state = (State)Random::Range(1, 1);

		if (state == State::WALK) {
			// �̵� Ready
		}
		else if (state == State::ATTACK) {
			// ���� Ready
		}
	}

	/////////////////////////////////////////////////////////// ���� Update
	if (state == State::WALK) {
		//1.5f �ð����� �Ȱ� �� 3�� �ݺ�
		MoveRandomPattern(1.5f, 3);
	}

}


