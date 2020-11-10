#include "stdafx.h"
#include "Blastoise.h"

Blastoise::Blastoise()
{
	Initialize();
}

Blastoise::Blastoise(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	direction = dir;
	stat.level = lv;
	Initialize();

}

Blastoise::~Blastoise()
{
}

void Blastoise::Initialize()
{
	name = L"°ÅºÏ¿Õ";
	type = TYPE::BLASTOISE;
	number = Pokemon::Blastoise;

	SetTexture(State::IDLE, TextureKey::PW03_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PW03_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PW03_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::PW03_SKILL_D_01, 1);

	offsetY = 0.13f;

	state = State::IDLE;
	AnimSet();

	increaseAttack = 5.f;
	increaseMaxHp = 30.f;

	defaultAttack = 100.f;
	defaultMaxHp = 600;

	SetStatByLevel();

	skillSet.reserve(4);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterCannon));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Blaze));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::XClaw));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Meteor));

	UpdateAnimation();
}

void Blastoise::Update()
{
	Character::Update();
}

void Blastoise::Render()
{
	Character::Render();
}

void Blastoise::Release()
{
}

void Blastoise::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Blastoise::AnimSet()
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

bool Blastoise::Attack(const Vector3& dir, const int& attackType)
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

Blastoise* Blastoise::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Blastoise* newPokemon = new Blastoise(pos, dir, lv);
	return newPokemon;
}
