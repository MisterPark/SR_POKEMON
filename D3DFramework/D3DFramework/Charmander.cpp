#include "stdafx.h"
#include "Charmander.h"

Charmander::Charmander()
{
	Initialize();
}

Charmander::Charmander(const Vector3 & pos, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;

	Initialize();
}

Charmander::~Charmander()
{
}

void Charmander::Initialize()
{
	name = L"ÆÄÀÌ¸®";
	number = Pokemon::Charmander;

	SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	stat.attack = 30;

	stat.hp = 250;
	stat.maxHp = 250;

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

Charmander * Charmander::Create(const Vector3 & pos, const Vector3 & dir)
{
	Charmander* newPokemon = new Charmander(pos, dir);
	return newPokemon;
}
