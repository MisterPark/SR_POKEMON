#include "stdafx.h"
#include "Squirtle.h"

Squirtle::Squirtle()
{
    Initialize();
}

Squirtle::Squirtle(const Vector3& pos, const Vector3& dir,int lv)
{
    transform->position = pos;
    transform->scale = { 0.2f, 0.2f, 0.2f };
    direction = dir;
	stat.level = lv;
    Initialize();

}

Squirtle::~Squirtle()
{
}

void Squirtle::Initialize()
{
	name = L"���α�";
	type = TYPE::SQUIRTLE;
	number = Pokemon::Squirtle;

	SetTexture(State::IDLE, TextureKey::PW01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PW01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PW01_ATTACK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::PW01_SKILL_D_01, 1);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 1.5f;
	increaseMaxHp = 12.5f;

	defaultAttack = 30.f;
	defaultMaxHp = 250;

	SetStatByLevel();

	skillSet.reserve(2);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterFlow));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBomb));

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
			ChangeState(State::ATTACK);
			anim->SetTick(0.f);
			break;

		}

		return true;
	}
	return false;
}

Squirtle* Squirtle::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Squirtle* newPokemon = new Squirtle(pos, dir, lv);
	return newPokemon;
}
