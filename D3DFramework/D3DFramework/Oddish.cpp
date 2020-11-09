#include "stdafx.h"
#include "Oddish.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"
#include "Bullet.h"

Oddish::Oddish()
{
	Initialize();
}

Oddish::Oddish(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	Initialize();
}

Oddish::~Oddish()
{
}

void Oddish::Initialize()
{
	name = L"¶Ñ¹÷ÃÊ";
	type = TYPE::ODDISH;
	number = Pokemon::Oddish;

	SetTexture(State::WALK, TextureKey::ODDI_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::ODDI_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::ODDI_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::ODDI_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::ODDI_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterCannon));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterCannon));

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 30;
	defaultMaxHp = 100;

	increaseAttack = defaultAttack * 0.05;
	increaseMaxHp = defaultMaxHp * 0.05;
	
	SetStatByLevel();
	UpdateAnimation();
}

void Oddish::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Oddish::Render()
{
	Character::Render();
}

void Oddish::Release()
{
}

bool Oddish::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		if (team == Team::PLAYERTEAM) {
			switch (attackType)
			{
			case 0: ChangeState(State::ATTACK); break;
			case 1: ChangeState(State::ATTACK); break;
			}
		}
		return true;
	}
	return false;
}

Oddish* Oddish::Create(const Vector3& pos, const Vector3& dir)
{
	Oddish* newPokemon = new Oddish(pos, dir);
	return newPokemon;
}
