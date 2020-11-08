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
	number = Pokemon::Squirtle;

	SetTexture(State::IDLE, TextureKey::PW01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PW01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PW01_ATTACK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::PW01_SKILL_D_01, 1);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	stat.attack = 30;

	stat.hp = 250;
	stat.maxHp = 250;

	skillSet.reserve(2);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterFlow));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::ShellAttack));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBomb));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Tsunami));

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
		anim->SetLoop(false);
		anim->SetDelay(0.2f);
		anim->SetTick(0.f);
		break;
	case State::SKILL:
		anim->SetLoop(false);
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
			ChangeState(State::SKILL);
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
