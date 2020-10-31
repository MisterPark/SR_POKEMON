#include "stdafx.h"
#include "Bulbasaur.h"
#include "PlayerBullet.h"

Bulbasaur::Bulbasaur()
{
	Initialize();
}

Bulbasaur::Bulbasaur(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Bulbasaur::~Bulbasaur()
{
}

void Bulbasaur::Initialize()
{
	name = L"ÀÌ»óÇØ¾¾";
	SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG01_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG01_SKILL_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	offsetY = 0.13f;

	state = State::IDLE;

	UpdateAnimation();
}

void Bulbasaur::Update()
{
	Character::Update();
}

void Bulbasaur::Render()
{
	Character::Render();
}

void Bulbasaur::Release()
{
}

void Bulbasaur::Attack(const Vector3 & dir)
{
	Vector3 pos = transform->position;

	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.01f, 0.01f, 0.01f }, dir, 0);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::ATTACK);
}

void Bulbasaur::Skill(const Vector3 & dir)
{
	Vector3 pos = transform->position;

	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.01f, 0.01f, 0.01f }, dir, 0);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::SKILL);
}

Bulbasaur * Bulbasaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Bulbasaur* newPokemon = new Bulbasaur(pos, scale, dir);
	return newPokemon;
}
