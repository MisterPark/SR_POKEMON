#include "stdafx.h"
#include "Butterfree.h"
#include "Bullet_Water.h"
Butterfree::Butterfree()
{
	name = L"�����ö���";
	//SetTexture( ����, ó���ؽ���, �ϳ��� ���� �����Ӽ�);
	SetTexture(State::WALK, TextureKey::BUTTER_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::BUTTER_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::BUTTER_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::BUTTER_ATTACK_D_01, 2);
	
	UpdateAnimation();
	anim->SetLoop(true);

	moveSpeed = 2.5f;
	offsetY = 2.5f;
	state = State::WALK;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Butterfree::~Butterfree()
{
}


void Butterfree::Update()
{
	Pattern();
	Monster::Update();

}

void Butterfree::Render()
{
	Monster::Render();
}

void Butterfree::Pattern()
{
	/////////////////////////////////////////////////////////// �÷��̾� Ž��
	PlayerSearch(6.f, 10.f);


	/////////////////////////////////////////////////////////// �÷��̾� Ž�� TRUE
	if (isSearch) {

		/////////////////////////////////////////////////////////// ���� Ready
		if (state == State::READY) {
			
			if (disPlayer < 7.f) {
				state = State::ATTACK;
			}
			else {//if (disPlayer > 10.f)
				state = State::WALK;
				anim->SetDelay(0.3f);
			}
		}

		/////////////////////////////////////////////////////////// ���� Update
		if (state == State::WALK) {
			if (disPlayer < 7.f) {
				state = State::ATTACK;
			}
			else if (disPlayer > 10.f) {

			}
			else {//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
		}
		else if (state == State::ATTACK) {
			direction = DirFromPlayer(true);
			Attack();
		}

	}



	/////////////////////////////////////////////////////////// �÷��̾� Ž�� FALSE
	else {

		/////////////////////////////////////////////////////////// ���� Ready
		if (state == State::READY) {
			state = (State)Random::Range(1, 1);

			if (state == State::WALK) {
				
			}
			else if (state == State::ATTACK) {
				// ���� Ready
				anim->SetDelay(0.3f);
			}
		}

		/////////////////////////////////////////////////////////// ���� Update
		if (state == State::WALK) {
			//1.5f �ð����� �Ȱ� �� 3�� �ݺ�
			MoveRandomPattern(1.5f, 3);
		}
		else if (state == State::ATTACK) {
			Attack();
		}
	}


}


void Butterfree::Attack()
{
	Time[1] += TimeManager::DeltaTime();

	if (Time[1] >= 0.3f) {
		Time[0] = 0;
		Frame[1]++;
		if (Frame[1] == 1) {
			Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			b->SetDir(direction);
			*(b->transform) = *transform;
			b->transform->position.y -= 0.5f;
		}
		else if (Frame[1] == 2) {
			anim->SetDelay(0.2f);
			Time[1] = 0.f;
			Frame[1] = 0.f;
			state = State::READY;
		}
	}
}