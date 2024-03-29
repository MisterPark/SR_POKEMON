#include "stdafx.h"
#include "Charizard.h"

Charizard::Charizard()
{
	Initialize();
}

Charizard::Charizard(const Vector3 & pos, const Vector3 & dir, int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();
}

Charizard::~Charizard()
{
}

void Charizard::Initialize()
{
	name = L"���ڸ�";
	type = TYPE::CHARIZARD;
	number = Pokemon::Charizard;

	SetTexture(State::IDLE, TextureKey::PF03_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF03_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PF03_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PF03_ATTACK_D_01, 2);

	offsetY = 0.15f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 5.f;
	increaseMaxHp = 30.f;

	defaultAttack = 100.f;
	defaultMaxHp = 600;

	SetStatByLevel();

	skillSet.reserve(4);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Blaze));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::XClaw));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Meteor));

	UpdateAnimation();
}

void Charizard::Update()
{
	Character::Update();
}

void Charizard::Render()
{
	Character::Render();
}

void Charizard::Release()
{
}

void Charizard::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Charizard::AnimSet()
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
		anim->SetDelay(1.4f);
		anim->SetTick(0.f);
		break;
	case State::HURT:
		break;
	}
}

bool Charizard::Attack(const Vector3 & dir, const int & attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		case 1: ChangeState(State::ATTACK); break;
		case 2: ChangeState(State::SKILL); break;
		case 3: ChangeState(State::SKILL); break;
		}

		return true;
	}
	return false;
}

Charizard * Charizard::Create(const Vector3 & pos, const Vector3 & dir, int lv)
{
	Charizard* newPokemon = new Charizard(pos, dir, lv);
	return newPokemon;
}
