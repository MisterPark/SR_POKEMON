#include "stdafx.h"
#include "Scyther.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Scyther::Scyther()
{
	name = L"����ũ";
	SetTexture(State::WALK, TextureKey::SCY_WALK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::SCY_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SCY_WALK_D_01, 3, 1);

	anim->SetLoop(true);
	UpdateAnimation();

	offsetY = 1.5f;
	moveSpeed = 3.f;
	state = State::READY;
	transform->scale *= 1.5f;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
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
	/////////////////////////////////////////////////////////// �÷��̾� Ž��
	PlayerSearch(8.f, 20.f);


	/////////////////////////////////////////////////////////// �÷��̾� Ž�� TRUE
	if (isSearch) {

		/////////////////////////////////////////////////////////// ���� Ready
		if (state == State::READY) {
			//state = (State)Random::Range(1, 1);
			if (disPlayer > 5.5f && disPlayer < 20.f) {
				state = State::SKILL;
			}
			if (state == State::SKILL) {
				anim->SetDelay(1.5f);
			}
			
		}

		/////////////////////////////////////////////////////////// ���� Update
		if (state == State::WALK) {
			//1.5f �ð����� �Ȱ� �� 3�� �ݺ�
			MoveRandomPattern(1.5f, 1);
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
			
		}

		/////////////////////////////////////////////////////////// ���� Update
		if (state == State::WALK) {
			//1.5f �ð����� �Ȱ� �� 3�� �ݺ�
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

