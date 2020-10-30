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
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
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
	/////////////////////////////////////////////////////////// �÷��̾� Ž��
	PlayerSearch(6.f, 10.f);


	/////////////////////////////////////////////////////////// �÷��̾� Ž�� TRUE
	if (isSearch) {

		if (state == State::READY) { // �̰� �������� ������ ������
			state = (State)Random::Range(1, 1); // ���� �������ִ°� (����)

			if (state == State::WALK) {            // �̰����� ���� ����
				// �̵� Ready
			}
			else if (state == State::ATTACK) {
				// ���� Ready
			}
		}

		/////////////////////////////////////////////////////////// ���� Update
		if (state == State::WALK) {
			MovePlayerFollow();
		}
		else if (state == State::ATTACK) {
			// ���� Update
		}

	}



	/////////////////////////////////////////////////////////// �÷��̾� Ž�� FALSE
	else {

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
		else if (state == State::ATTACK) {
			// ���� Update
		}
	}


}


