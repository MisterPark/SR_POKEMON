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

Suicune::Suicune(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Suicune::~Suicune()
{
}

void Suicune::Initialize()
{
	name = L"½ºÀÌÄï";
	SetTexture(State::WALK, TextureKey::SUI_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::SUI_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SUI_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SUI_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SUI_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 3.5f;
	offsetY = 1.f;

	state = State::READY;

	hp = 1600;
	maxHp = 1600;
	attack = 50.f;

	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::BubbleBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::BubbleBullet2));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::IceBullet));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::IceBullet2));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::IceBullet3));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::IceBullet4));

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

Suicune* Suicune::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Suicune* newPokemon = new Suicune(pos, scale, dir);
	return newPokemon;
}