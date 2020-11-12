#include "stdafx.h"
#include "Venusaur.h"

Venusaur::Venusaur()
{
	Initialize();
}

Venusaur::Venusaur(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();

}

Venusaur::~Venusaur()
{
}

void Venusaur::Initialize()
{
	name = L"ÀÌ»óÇØ²É";
	type = TYPE::VENUSAUR;
	number = Pokemon::Venusaur;

	SetTexture(State::IDLE, TextureKey::PG03_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG03_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PG03_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG03_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 5.f;
	increaseMaxHp = 30.f;

	defaultAttack = 100.f;
	defaultMaxHp = 600;

	SetStatByLevel();

	skillSet.reserve(4);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::LeafShot));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Synthesis));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::LeechSeed));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::PetalBlizzard));

	UpdateAnimation();
}

void Venusaur::Update()
{
	Character::Update();
}

void Venusaur::Render()
{
	Character::Render();
}

void Venusaur::Release()
{
}

void Venusaur::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Venusaur::AnimSet()
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

bool Venusaur::Attack(const Vector3& dir, const int& attackType)
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
		case 2:
			ChangeState(State::SKILL);
			anim->SetTick(0.f);
			break;
		case 3:
			ChangeState(State::SKILL);
			anim->SetTick(0.f);
			break;
		}

		return true;
	}
	return false;
}

Venusaur* Venusaur::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Venusaur* newPokemon = new Venusaur(pos, dir, lv);
	return newPokemon;
}
