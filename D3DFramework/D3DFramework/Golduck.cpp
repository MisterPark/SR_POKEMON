#include "stdafx.h"
#include "Golduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Golduck::Golduck()
{
	SetTexture(State::WALK, TextureKey::GOLD_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::GOLD_ATTACK_D_01, 2);
	SetTexture(State::IDLE, TextureKey::GOLD_WALK_D_01, 3);

	for (int i = 0; i < 8; i++)
	{
		endArray[(int)State::IDLE][(int)Direction::D + i] = (TextureKey)((int)endArray[(int)State::IDLE][(int)Direction::D + i] - 2);
	}
	transform->position.x = 10.f;
	anim->SetLoop(true);
	UpdateAnimation();

	offsetY = 1.f;
	state = State::END;
	moveSpeed = 0.5f;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Golduck::~Golduck()
{
}

void Golduck::Update()
{
	Pattern();
	Monster::Update();
}

void Golduck::Render()
{
	Monster::Render();
}

void Golduck::Pattern()
{


	GameObject* g = Player::GetInstance()->GetCharacter();
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);


	float radian1 = PlayerT->scale.x / 2;
	float radian2 = transform->scale.x / 2;

	if (!isSearch)
	{
		if (Dist < 5.f) {
			isSearch = true;
			state = State::READY;
		}

		if (state == State::READY && !isSearch)
		{
			state = State::WALK;
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			direction.Normalized();
		}
		if (state == State::WALK) {		//// �̰����� ������Ʈ
			RandomMovePattern();
		}
	}

	if (isSearch)
	{

		if (state == State::READY && Dist < 3.f)
		{
			state = State::ATTACK;

		}
		if (state == State::READY && Dist >= 3.f)
		{
			Vector3 Dist = PlayerT->position - transform->position;
			direction = Dist.Normalized();
			state = State::WALK;
			Frame[0] = 0;
		}

		if (state == State::WALK) {		//// �̰����� ������Ʈ
			Time[0] += TimeManager::DeltaTime();
			transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
			transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();
			if (Time[0] >= 1.5f) {
				Frame[0] ++;
				Time[0] = 0;
				if (Frame[0] == 2) {			// 4���� �ĴڰŸ� ��
					Frame[0] = 0;
					state = State::ATTACK;
				}
			}
		}
		if (state == State::ATTACK)
		{
			Attack(PlayerT);
		}
	}

}

void Golduck::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 4) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::END;
		}
	}
}

void Golduck::Attack(Transform* PlayerT)
{
	Time[0] += TimeManager::DeltaTime();
	if (!AttackDelay && Time[0] >= 0.3f) {
		AttackDelay = true;
		CreateBullet(PlayerT);
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

void Golduck::CreateBullet(Transform* PlayerT)
{
	direction = PlayerT->position - transform->position;
	//MoveDir *= 1.5f;
	float R = 0.5f;
	if (direction.x > direction.z) {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Vector3{ Dir2.x, Dir2.y, Dir2.z });
		*(b->transform) = *transform;
		b->isAlliance = false;
	}
	else {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Vector3{ Dir2.x, Dir2.y, Dir2.z });
		*(b->transform) = *transform;
		b->isAlliance = false;
	}
}
