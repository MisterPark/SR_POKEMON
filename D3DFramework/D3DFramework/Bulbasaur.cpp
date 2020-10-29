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
	SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG01_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 2);

	anim->SetLoop(true);
	offsetY = 0.2f;

	state = State::IDLE;
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
	pos.y += offsetY;
	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.2f, 0.2f, 0.2f }, dir, 0);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::ATTACK);
}

void Bulbasaur::Skill(const Vector3 & dir)
{
}

Bulbasaur * Bulbasaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Bulbasaur* newPokemon = new Bulbasaur(pos, scale, dir);
	return newPokemon;
}
