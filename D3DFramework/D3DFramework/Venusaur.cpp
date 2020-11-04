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
	number = Pokemon::Venusaur;

	SetTexture(State::IDLE, TextureKey::PG03_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG03_WALK_D_02, 3,2);
	SetTexture(State::ATTACK, TextureKey::PG03_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG03_SKILL_D_01, 2);

	anim->SetLoop(true);
	offsetY = 0.13f;

	attack = 100;

	hp = 1000;
	maxHp = 1000;

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

bool Venusaur::Attack(const Vector3 & dir, const int & attackType)
{
	if (Character::Attack(dir, attackType))
	{
		/*
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		case 1: ChangeState(State::ATTACK); break;
		}
		*/

		return true;
	}
	return false;
}

Venusaur * Venusaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Venusaur* newPokemon = new Venusaur(pos, scale, dir);
	return newPokemon;
}
