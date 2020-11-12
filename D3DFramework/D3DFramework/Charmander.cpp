#include "stdafx.h"
#include "Charmander.h"

Charmander::Charmander()
{
	Initialize();
}

Charmander::Charmander(const Vector3 & pos, const Vector3 & dir, int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();
}

Charmander::~Charmander()
{
}

void Charmander::Initialize()
{
	name = L"ÆÄÀÌ¸®";
	type = TYPE::CHARMANDER;
	number = Pokemon::Charmander;

	SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 1.5f;
	increaseMaxHp = 12.5f;

	defaultAttack = 30.f;
	defaultMaxHp = 250;

	SetStatByLevel();

	skillSet.reserve(2);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Blaze));

	UpdateAnimation();
}

void Charmander::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Charmander::Render()
{
	Character::Render();
}

void Charmander::Release()
{
}

void Charmander::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Charmander::AnimSet()
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

bool Charmander::Attack(const Vector3 & dir, const int & attackType)
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

Charmander * Charmander::Create(const Vector3 & pos, const Vector3 & dir, int lv)
{
	Charmander* newPokemon = new Charmander(pos, dir, lv);
	return newPokemon;
}
