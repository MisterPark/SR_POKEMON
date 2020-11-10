#include "stdafx.h"
#include "Suicune.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Suicune::Suicune()
{
	Initialize();
}

Suicune::Suicune(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	Initialize();
}

Suicune::~Suicune()
{
}

void Suicune::Initialize()
{
	name = L"½ºÀÌÄï";
	type = TYPE::SUICUNE;
	number = Pokemon::Suicune;

	SetTexture(State::WALK, TextureKey::SUI_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::SUI_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SUI_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SUI_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SUI_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::SUI_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 3.5f;
	offsetY = 1.5f;

	state = State::READY;

	transform->scale = { 1.5f, 1.5f, 1.5f };

	defaultMaxHp = 2000;
	defaultAttack = 50.f;

	increaseAttack = defaultAttack * 0.05;
	increaseMaxHp = defaultMaxHp * 0.05;
	stat.money = 10;

	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::BubbleShot));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::AccelWater));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::SnowRain));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::SnowVulcan));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::SnowFall));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::SnowCrystal));

	SetStatByLevel();
	UpdateAnimation();

}

void Suicune::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Suicune::Render()
{
	Character::Render();
}

void Suicune::Release()
{
}

bool Suicune::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0:
			ChangeState(State::ATTACK);
			//anim->SetDelay(animDelay);
			//anim->SetTick(0.f);

			break;
		case 1: ChangeState(State::ATTACK); break;
		}
		return true;
	}
	return false;
}

Suicune* Suicune::Create(const Vector3& pos, const Vector3& dir)
{
	Suicune* newPokemon = new Suicune(pos, dir);
	return newPokemon;
}