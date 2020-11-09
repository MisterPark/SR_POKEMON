#include "stdafx.h"
#include "Ditto.h"

Ditto::Ditto()
{
	Initialize();
}

Ditto::Ditto(const Vector3 & pos, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = { 0.5f, 0.5f, 0.5f };
	direction = dir;

	Initialize();
}

Ditto::~Ditto()
{
}

void Ditto::Initialize()
{
	name = L"��Ÿ��";
	number = Pokemon::Ditto;

	SetTexture(State::IDLE, TextureKey::DITTO_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::DITTO_WALK_D_02, 3, 2);

	offsetY = 0.5f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 1.5f;
	increaseMaxHp = 12.5f;

	defaultAttack = 30.f;
	defaultMaxHp = 250;

	SetStatByLevel();
}

void Ditto::Update()
{
	Character::Update();
}

void Ditto::Render()
{
	Character::Render();
}

void Ditto::Release()
{
}

void Ditto::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Ditto::AnimSet()
{
	switch (state)
	{
	case State::IDLE:
		anim->SetLoop(false);
		anim->SetDelay(0.1f);
		anim->SetTick(0.f);
		break;
	case State::WALK:
		anim->SetLoop(true);
		anim->SetDelay(0.15f);
		anim->SetTick(0.f);
		break;
	}
}

bool Ditto::Attack(const Vector3 & dir, const int & attackType)
{
	if (Character::Attack(dir, attackType))
	{
		return true;
	}
	return false;
}

Ditto * Ditto::Create(const Vector3 & pos, const Vector3 & dir)
{
	Ditto* newPokemon = new Ditto(pos, dir);
	return newPokemon;
}