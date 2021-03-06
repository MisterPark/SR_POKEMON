#include "stdafx.h"
#include "Ditto.h"

Ditto::Ditto()
{
	Initialize();
}

Ditto::Ditto(const Vector3 & pos, const Vector3 & dir, int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();
}

Ditto::~Ditto()
{
}

void Ditto::Initialize()
{
	name = L"��Ÿ��";
	type = TYPE::DITTO;
	number = Pokemon::Ditto;
	
	switch (Player::GetInstance()->GetDittoColor())
	{
	case 0:
		SetTexture(State::IDLE, TextureKey::DITTO_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::DITTO_WALK_D_02, 3, 2);
		break;
	case 1:
		SetTexture(State::IDLE, TextureKey::DITTOR_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::DITTOR_WALK_D_02, 3, 2);
		break;
	case 2:
		SetTexture(State::IDLE, TextureKey::DITTOY_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::DITTOY_WALK_D_02, 3, 2);
		break;
	case 3:
		SetTexture(State::IDLE, TextureKey::DITTOG_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::DITTOG_WALK_D_02, 3, 2);
		break;
	case 4:
		SetTexture(State::IDLE, TextureKey::DITTOB_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::DITTOB_WALK_D_02, 3, 2);
		break;
	default:
		break;
	}

	offsetY = 0.2f;

	state = State::IDLE;
	AnimSet();
	UpdateAnimation();

	increaseAttack = 10.f;
	increaseMaxHp = 20.f;

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

Ditto * Ditto::Create(const Vector3 & pos, const Vector3 & dir, int lv)
{
	Ditto* newPokemon = new Ditto(pos, dir, lv);
	return newPokemon;
}
