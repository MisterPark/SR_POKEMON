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
	number = Pokemon::Bulbasaur;

	SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG01_WALK_D_02, 3,2);
	SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG01_SKILL_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	offsetY = 0.13f;

	state = State::IDLE;

	stat.attack = 30;

	stat.hp = 250;
	stat.maxHp = 250;

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

bool Bulbasaur::Attack(const Vector3 & dir, const int & attackType)
{
	if (Character::Attack(dir, attackType))
	{
		/*switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		case 1: ChangeState(State::ATTACK); break;
		}*/

		return true;
	}
	return false;
}

Bulbasaur * Bulbasaur::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Bulbasaur* newPokemon = new Bulbasaur(pos, scale, dir);
	return newPokemon;
}
