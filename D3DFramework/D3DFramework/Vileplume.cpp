#include "stdafx.h"
#include "Vileplume.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Vileplume::Vileplume()
{
	Initialize();
}

Vileplume::Vileplume(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Vileplume::~Vileplume()
{
}

void Vileplume::Initialize()
{
	name = L"라플레시아";
	SetTexture(State::WALK, TextureKey::VILE_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::VILE_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::VILE_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::VILE_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::VILE_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 1.f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	UpdateAnimation();
}

void Vileplume::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Vileplume::Render()
{
	Character::Render();
}

void Vileplume::Release()
{
}

void Vileplume::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Vileplume* Vileplume::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Vileplume* newPokemon = new Vileplume(pos, scale, dir);
	return newPokemon;
}

/*
void Vileplume::Pattern()
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

		else if (state == State::READY)
		{
			state = State::WALK;
			direction.x = -4.f + Random::Value(9) * 1.f;
			direction.y = 0.f;
			direction.z = -4.f + Random::Value(9) * 1.f;
			direction.Normalize(&direction);
		}
		if (state == State::WALK) {		//// 이곳부터 업데이트
			RandomMovePattern();
		}
	}

	if (isSearch)
	{
		if (Dist > 10.f)
		{
			isSearch = false;
			Frame[0] = 0;
			state = State::READY;
		}

		else if (state == State::READY && Dist < 3.f)
		{
			state = State::ATTACK;

		}
		else if (state == State::READY && Dist >= 3.f)
		{
			Vector3 Dist = PlayerT->position - transform->position;
			direction = Dist.Normalized();
			state = State::WALK;
			Frame[0] = 0;
		}

		if (state == State::WALK) {		//// 이곳부터 업데이트
			Time[0] += TimeManager::DeltaTime();
			float moveX = direction.x * moveSpeed * TimeManager::DeltaTime();
			float moveZ = direction.z * moveSpeed * TimeManager::DeltaTime();

			if (moveX > 0.05f)
			{
				moveX = 0.05f;
			}
			if (moveZ > 0.05f)
			{
				moveZ = 0.05f;
			}

			transform->position.x += moveX;
			transform->position.z += moveZ;
			if (Time[0] >= 1.5f) {
				Frame[0] ++;
				Time[0] = 0;
				if (Frame[0] == 2) {			// 4번의 파닥거림 후
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

void Vileplume::RandomMovePattern()
{
	Time[0] += TimeManager::DeltaTime();

	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();

	if (Time[0] >= 1.5f) {
		Frame[0] ++;
		Time[0] = 0;
		if (Frame[0] == 2) {			// 4번의 파닥거림 후
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
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;
}

void Vileplume::XBullet()
{
	float R = 1.f;

	Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Vector3 Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z -= R;
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;
}

*/