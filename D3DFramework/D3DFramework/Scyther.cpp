#include "stdafx.h"
#include "Scyther.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Scyther::Scyther()
{
	SetTexture(State::WALK, TextureKey::SCY_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::SCY_WALK_D_01, 3);
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

	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	Transform* PlayerT = g->transform;



	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);


	if (state != State::PLAYER_SEARCH && Dist > 10.f) {
		state = State::PLAYER_SEARCH;
		//�̰����� �÷��̾� ���ϴ� ���⺤�� �����ְ�
		direction = PlayerT->position - transform->position;
		direction.Normalized();
		anim->SetDelay(1.5f);
		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::READY) { // �̰� �������� ������ ������
		state = (State)Random::Range(1, 1); // ���� �������ִ°� (����)

		if (state == State::WALK) {            // �̰����� ���� ����
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.y = 0.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			direction.Normalize(&direction);
		}
	}
	else if (state == State::WALK) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}
	else if (state == State::PLAYER_SEARCH) {
		Time[0] += TimeManager::DeltaTime();
		if (1.5f < Time[0]) {
			transform->position.x += direction.x * (moveSpeed * 2.1f) * TimeManager::DeltaTime();
			transform->position.z += direction.z * (moveSpeed * 2.1f) * TimeManager::DeltaTime();
			if (1.65f < Time[0]) {
				state = State::READY;
				Time[0] = 0;
				Frame[0] = 0;
				anim->SetDelay(0.2f);
				SkillBullet();
				return;
			}
		}
	}

}

void Scyther::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::READY;
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
			b->transform->position.y = 0.3f;
			b->transform->scale.x = 0.7f;
			b->transform->scale.y = 0.7f;
			b->transform->scale.z = 0.7f;
			//b->moveSpeed = 0.5f;
		}
	}
}

