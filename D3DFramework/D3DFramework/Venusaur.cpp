#include "stdafx.h"
#include "Venusaur.h"
#include "PlayerBullet.h"

Venusaur::Venusaur()
{
	Initialize();
}

Venusaur::Venusaur(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Venusaur::~Venusaur()
{
}

void Venusaur::Initialize()
{
	name = L"ÀÌ»óÇØ²É";
	SetTexture(State::IDLE, TextureKey::PG03_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG03_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PG03_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG03_SKILL_D_01, 2);

	anim->SetLoop(true);
	offsetY = 0.13f;

	state = State::IDLE;
}

void Venusaur::Update()
{
	Character::Update();
}

void Venusaur::Render()
{
	Character::Render();
}

void Venusaur::Release()
{
}

void Venusaur::Attack(const Vector3 & dir)
{
	Vector3 pos = transform->position;
	pos.y += offsetY;
	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.1f, 0.1f, 0.05f }, dir, 0);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::ATTACK);
}

void Venusaur::Skill(const Vector3 & dir)
{
}

Venusaur * Venusaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Venusaur* newPokemon = new Venusaur(pos, scale, dir);
	return newPokemon;
}
