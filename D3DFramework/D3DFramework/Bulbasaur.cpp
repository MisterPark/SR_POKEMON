#include "stdafx.h"
#include "Bulbasaur.h"
#include "Bullet.h"

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
	PlayerCharacter::Update();
}

void Bulbasaur::Render()
{
	PlayerCharacter::Render();
}

void Bulbasaur::Release()
{
}

void Bulbasaur::Attack(const Vector3 & dir)
{
	Bullet* newBullet = Bullet::Create(transform->position, { 1.f, 1.f, 1.f }, dir, 0);
	ObjectManager::AddObject(newBullet);
}

void Bulbasaur::Skill(const Vector3 & dir)
{
}

Bulbasaur * Bulbasaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Bulbasaur* newBulbasaur = new Bulbasaur(pos, scale, dir);
	return newBulbasaur;
}
