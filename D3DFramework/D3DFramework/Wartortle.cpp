#include "stdafx.h"
#include "Wartortle.h"

Wartortle::Wartortle()
{
	Initialize();
}

Wartortle::Wartortle(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();

}

Wartortle::~Wartortle()
{
}

void Wartortle::Initialize()
{
	name = L"어니부기";
	type = TYPE::WARTORTLE;
	number = Pokemon::Wartortle;

	SetTexture(State::IDLE, TextureKey::PW02_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PW02_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PW02_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PW02_SKILL_D_01, 1);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 2.5f;
	increaseMaxHp = 22.5f;

	defaultAttack = 50.f;
	defaultMaxHp = 450;

	SetStatByLevel();

	skillSet.reserve(3);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterFlow));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBomb));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Tsunami));

	UpdateAnimation();
}

void Wartortle::Update()
{
	Character::Update();
}

void Wartortle::Render()
{
	Character::Render();
}

void Wartortle::Release()
{
}

void Wartortle::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Wartortle::AnimSet()
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

bool Wartortle::Attack(const Vector3& dir, const int& attackType)
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
		case 2:
			ChangeState(State::ATTACK);
			anim->SetTick(0.f);
			break;
		}

		return true;
	}
	return false;
}

Wartortle* Wartortle::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Wartortle* newPokemon = new Wartortle(pos, dir, lv);
	return newPokemon;
}
