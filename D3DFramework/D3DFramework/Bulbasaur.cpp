#include "stdafx.h"
#include "Bulbasaur.h"

Bulbasaur::Bulbasaur()
{
	Initialize();
}

Bulbasaur::Bulbasaur(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();

}

Bulbasaur::~Bulbasaur()
{
}

void Bulbasaur::Initialize()
{
	name = L"ÀÌ»óÇØ¾¾";
	type = TYPE::BULBASAUR;
	number = Pokemon::Bulbasaur;

	SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG01_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 1.5f;
	increaseMaxHp = 12.5f;

	defaultAttack = 30.f;
	defaultMaxHp = 250;

	SetStatByLevel();

	skillSet.reserve(2);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::LeafShot));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Synthesis));

	UpdateAnimation();
}

void Bulbasaur::Update()
{
	Character::Update();
}

void Bulbasaur::Render()
{
	Character::Render();
}

void Bulbasaur::Release()
{
}

void Bulbasaur::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Bulbasaur::AnimSet()
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

bool Bulbasaur::Attack(const Vector3& dir, const int& attackType)
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

Bulbasaur* Bulbasaur::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Bulbasaur* newPokemon = new Bulbasaur(pos, dir, lv);
	return newPokemon;
}
