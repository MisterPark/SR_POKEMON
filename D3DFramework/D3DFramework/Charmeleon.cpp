#include "stdafx.h"
#include "Charmeleon.h"

Charmeleon::Charmeleon()
{
	Initialize();
}

Charmeleon::Charmeleon(const Vector3 & pos, const Vector3 & dir, int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();
}

Charmeleon::~Charmeleon()
{
}

void Charmeleon::Initialize()
{
	name = L"���ڵ�";
	type = TYPE::CHARMELEON;
	number = Pokemon::Charmeleon;

	SetTexture(State::IDLE, TextureKey::PF02_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF02_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PF02_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PF02_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 2.5f;
	increaseMaxHp = 22.5f;

	defaultAttack = 50.f;
	defaultMaxHp = 450;

	SetStatByLevel();

	skillSet.reserve(3);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Blaze));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::XClaw));

	UpdateAnimation();
}

void Charmeleon::Update()
{
	Character::Update();
}

void Charmeleon::Render()
{
	Character::Render();
}

void Charmeleon::Release()
{
}

void Charmeleon::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Charmeleon::AnimSet()
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
		anim->SetDelay(1.f);
		anim->SetTick(0.f);
		break;
	case State::HURT:
		break;
	}
}

bool Charmeleon::Attack(const Vector3 & dir, const int & attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		case 1: ChangeState(State::ATTACK); break;
		case 2: ChangeState(State::SKILL); break;
		}

		return true;
	}
	return false;
}

Charmeleon * Charmeleon::Create(const Vector3 & pos, const Vector3 & dir, int lv)
{
	Charmeleon* newPokemon = new Charmeleon(pos, dir, lv);
	return newPokemon;
}
