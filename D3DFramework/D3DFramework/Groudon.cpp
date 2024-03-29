#include "stdafx.h"
#include "Groudon.h"
#include "AllSkills.h"

Groudon::Groudon()
{
	Initialize();
}

Groudon::Groudon(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Groudon::~Groudon()
{
}

void Groudon::Initialize()
{
	name = L"�׶���";
	type = TYPE::GROUDON;
	number = Pokemon::Groudon;
	

	SetTexture(State::WALK, TextureKey::GROU_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::GROU_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::GROU_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::GROU_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::GROU_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::GROU_ATTACK_D_01, 2);
	SetTexture(State::SKILL3, TextureKey::GROU_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.5f;
	offsetY = 1.f;

	transform->scale = { 2.f, 2.f, 2.f };
	state = State::READY;

	defaultMaxHp = 1600;
	defaultAttack = 50.f;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBlast));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireWallWave));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Quake));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::ClawBlast));

	SetStatByLevel();
	UpdateAnimation();

}

void Groudon::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Groudon::Render()
{
	Character::Render();
}

void Groudon::Release()
{
}

bool Groudon::Attack(const Vector3& dir, const int& attackType)
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

Groudon* Groudon::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Groudon* newPokemon = new Groudon(pos, dir, lv);
	return newPokemon;
}