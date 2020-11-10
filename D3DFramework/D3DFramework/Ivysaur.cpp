#include "stdafx.h"
#include "Ivysaur.h"

Ivysaur::Ivysaur()
{
	Initialize();
}

Ivysaur::Ivysaur(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();

}

Ivysaur::~Ivysaur()
{
}

void Ivysaur::Initialize()
{
	name = L"이상해풀";
	type = TYPE::IVYSAUR;
	number = Pokemon::Ivysaur;

	SetTexture(State::IDLE, TextureKey::PG02_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG02_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PG02_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG02_SKILL_D_01, 2);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 2.5f;
	increaseMaxHp = 22.5f;

	defaultAttack = 50.f;
	defaultMaxHp = 450;

	SetStatByLevel();

	skillSet.reserve(3);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::LeafShot));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Synthesis));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::LeechSeed));

	UpdateAnimation();
}

void Ivysaur::Update()
{
	Character::Update();
}

void Ivysaur::Render()
{
	Character::Render();
}

void Ivysaur::Release()
{
}

void Ivysaur::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Ivysaur::AnimSet()
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

bool Ivysaur::Attack(const Vector3& dir, const int& attackType)
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
		}

		return true;
	}
	return false;
}

Ivysaur* Ivysaur::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Ivysaur* newPokemon = new Ivysaur(pos, dir, lv);
	return newPokemon;
}
