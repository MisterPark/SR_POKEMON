#include "stdafx.h"
#include "Squirtle.h"


Squirtle::Squirtle()
{
    Initialize();
}

Squirtle::Squirtle(const Vector3& pos, const Vector3& dir)
{
    transform->position = pos;
    transform->scale = { 0.2f, 0.2f, 0.2f };
    direction = dir;

    Initialize();

}


Squirtle::~Squirtle()
{
}

void Squirtle::Initialize()
{
	name = L"²¿ºÎ±â";
	number = Pokemon::Charmander;

	SetTexture(State::IDLE, TextureKey::PF02_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF02_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PF02_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::PF02_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	stat.attack = 30;

	skillSet.reserve(2);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Blaze));

	stat.hp = 250;
	stat.maxHp = 250;

	UpdateAnimation();
}

void Squirtle::Update()
{
	Character::Update();
}

void Squirtle::Render()
{
	Character::Render();
}

void Squirtle::Release()
{
}

void Squirtle::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Squirtle::AnimSet()
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
	case State::ATTACK:
		anim->SetLoop(true);
		anim->SetDelay(0.2f);
		anim->SetTick(0.f);
		break;
	case State::SKILL:
		anim->SetLoop(true);
		anim->SetDelay(0.2f);
		anim->SetTick(0.f);
		break;
	case State::HURT:
		break;
	}
}

bool Squirtle::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0:
			ChangeState(State::ATTACK);
			anim->SetTick(0.f);
			break;
		case 1:
			ChangeState(State::ATTACK);
			anim->SetTick(0.f);
			break;
		}

		return true;
	}
	return false;
}

Squirtle* Squirtle::Create(const Vector3& pos, const Vector3& dir)
{
	Squirtle* newPokemon = new Squirtle(pos, dir);
	return newPokemon;
}
