#include "stdafx.h"
#include "Ivysaur.h"
#include "PlayerBullet.h"

Ivysaur::Ivysaur()
{
	Initialize();
}

Ivysaur::Ivysaur(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Ivysaur::~Ivysaur()
{
}

void Ivysaur::Initialize()
{
	name = L"이상해풀";
	SetTexture(State::IDLE, TextureKey::PG02_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG02_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PG02_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG02_SKILL_D_01, 2);

	anim->SetLoop(true);
	offsetY = 0.13f;

	state = State::IDLE;
}

void Ivysaur::Update()
{
	Character::Update();
}

void Ivysaur::Render()
{
	Character::Render();
}

void Ivysaur::Release()
{
}

void Ivysaur::Attack(const Vector3 & dir)
{
	Vector3 pos = transform->position;
	pos.y += offsetY;
	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.2f, 0.2f, 0.2f }, dir, 0);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::ATTACK);
}

void Ivysaur::Skill(const Vector3 & dir)
{
}

Ivysaur * Ivysaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Ivysaur* newPokemon = new Ivysaur(pos, scale, dir);
	return newPokemon;
}
