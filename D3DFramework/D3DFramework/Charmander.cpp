#include "stdafx.h"
#include "Charmander.h"
#include "PlayerBullet.h"

Charmander::Charmander()
{
	Initialize();
}

Charmander::Charmander(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Charmander::~Charmander()
{
}

void Charmander::Initialize()
{
	name = L"ÆÄÀÌ¸®";
	SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF01_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	offsetY = 0.13f;

	state = State::IDLE;

	UpdateAnimation();
}

void Charmander::Update()
{
	Character::Update();
}

void Charmander::Render()
{
	Character::Render();
}

void Charmander::Release()
{
}

void Charmander::Attack(const Vector3 & dir)
{
	Vector3 pos = transform->position;

	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.01f, 0.01f, 0.01f }, dir, 1);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::ATTACK);
}

void Charmander::Skill(const Vector3 & dir)
{
	Vector3 pos = transform->position;

	PlayerBullet* newBullet = new PlayerBullet(pos, { 0.01f, 0.01f, 0.01f }, dir, 1);
	ObjectManager::AddObject(newBullet);

	ChangeState(State::SKILL);
}

Charmander * Charmander::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Charmander* newPokemon = new Charmander(pos, scale, dir);
	return newPokemon;
}
