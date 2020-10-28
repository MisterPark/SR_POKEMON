#include "stdafx.h"
#include "Psyduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Psyduck::Psyduck()
{
	SetTexture(State::WALK, TextureKey::PSY_WALK_D_01, 3);
	SetTexture(State::PLAYER_SEARCH, TextureKey::PSY_ATTACK2_D_01, 2);
	SetTexture(State::IDLE, TextureKey::PSY_WALK_D_01, 3);
	for (int i = 0; i < 8; i++)
	{
		endArray[(int)State::IDLE][(int)Direction::D + i] = (TextureKey)((int)endArray[(int)State::IDLE][(int)Direction::D + i] - 1);
	}
	anim->SetLoop(true);

	offsetY = 1.f;
	Speed = 0.5f;
	state = State::IDLE;
	AttackDelay = false;
	Monster::Update(); // ���� �������ڸ��� �Ѿ˽�� ��ġ�� 0�̶� �Ѿ��� ���� �������°� ����
}

Psyduck::~Psyduck()
{
}

void Psyduck::Update()
{
	Parttern();
	Monster::Update();
}

void Psyduck::Render()
{
	Monster::Render();
}

void Psyduck::Parttern()
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Player>();
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);



	if (state == State::IDLE && Dist < 8.f) {
		state = State::PLAYER_SEARCH;

		Time[0] = 0;
		Frame[0] = 0;
	}
	else if (state == State::IDLE) { // �̰� �������� ������ ������
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

void Psyduck::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 2) {			// 4���� �ĴڰŸ� ��
			Frame[0] = 0;
			state = State::IDLE;
		}
	}
}

void Psyduck::Attack(Transform * PlayerT)
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

void Psyduck::CreateBullet(Transform * PlayerT) {
	direction = PlayerT->position - transform->position;
	//MoveDir *= 1.5f;
	float R = 0.5f;
	if (direction.x > direction.z) {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		Dir2.z -= R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
		b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Dir2 = direction;
		Dir2.z += R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
	}
	else {
		Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Vector3 Dir2 = direction;
		Dir2.x -= R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
		b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
		Dir2 = direction;
		Dir2.x += R;
		D3DXVec3Normalize(&Dir2, &Dir2);
		b->SetDir(Dir2.x, Dir2.z, Dir2.y);
		*(b->transform) = *transform;
	}
}