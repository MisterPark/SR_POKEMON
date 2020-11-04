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
	number = Pokemon::Ivysaur;

	SetTexture(State::IDLE, TextureKey::PG02_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG02_WALK_D_02, 3,2);
	SetTexture(State::ATTACK, TextureKey::PG02_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG02_SKILL_D_01, 2);

	anim->SetLoop(true);
	offsetY = 0.13f;

	attack = 50;

	hp = 450;
	maxHp = 450;

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

bool Ivysaur::Attack(const Vector3 & dir, const int & attackType)
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

Ivysaur * Ivysaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Ivysaur* newPokemon = new Ivysaur(pos, scale, dir);
	return newPokemon;
}
