#include "stdafx.h"
#include "Vileplume.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Vileplume::Vileplume()
{
	SetTexture(State::WALK, TextureKey::VILE_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::VILE_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::VILE_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::VILE_WALK_D_01, 3, 1);

	anim->SetLoop(true);
	UpdateAnimation();

	moveSpeed = 0.5f;
	state = State::READY;
	AttackDelay = false;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Vileplume::~Vileplume()
{
}

void Vileplume::Update()
{
	Parttern();
	Monster::Update();
}

void Vileplume::Render()
{
	Monster::Render();
}

void Vileplume::Parttern()
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);



	if (state == State::READY && Dist < 8.f) {
		state = State::PLAYER_SEARCH;

		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::READY) { // �̰� �������� ������ ������
		state = (State)Random::Range(1, 1); // ���� �������ִ°� (����)

		if (state == State::WALK) {            // �̰����� ���� ����
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
		}
	}
	else if (state == State::WALK) {		//// �̰����� ������Ʈ
		RandomMovePattern();
	}
	else if (state == State::PLAYER_SEARCH) {
		Attack(PlayerT);
	}

}

void Vileplume::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 2) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::READY;
		}
	}
}

void Vileplume::Attack(Transform* PlayerT)
{
	Time[0] += TimeManager::DeltaTime();
	if (!AttackDelay && Time[0] >= 0.3f) {
		
		AttackDelay = true;
		if (Frame[0] % 2 == 1)
		CrossBullet();
		else
		XBullet();
	}
	if (Time[0] >= 0.6f) {
		Time[0] = 0.f;
		Frame[0]++;
		AttackDelay = false;
		if (Frame[0] == 3) {
			Frame[0] = 0;
			anim->SetDelay(0.2f);
			state = State::WALK;

		}
	}
}

void Vileplume::CrossBullet()
{
	float R = 1.f;

	Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Vector3 Dir2 = { 0.f,0.f,0.f };
	Dir2.z -= R;
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
}

void Vileplume::XBullet()
{
	float R = 1.f;

	Bullet_Water*	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Vector3 Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z -= R;
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
}

