#include "stdafx.h"
#include "Golduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"

Golduck::Golduck()
{
	Initialize();
}

Golduck::Golduck(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Golduck::~Golduck()
{
}

void Golduck::Initialize()
{
	name = L"���";
	type = TYPE::GOLDUCK;
	number = Pokemon::Golduck;

	SetTexture(State::WALK, TextureKey::GOLD_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::GOLD_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::GOLD_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::GOLD_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::GOLD_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;



	transform->scale = { 0.5f, 0.5f, 0.5f };

	defaultAttack = 35;
	defaultMaxHp = 200;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::AccelWater));

	SetStatByLevel();
	UpdateAnimation();
}

void Golduck::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();

}

void Golduck::Render()
{
	Character::Render();
}

void Golduck::Release()
{
}

bool Golduck::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		}
		return true;
	}
	return false;
}

Golduck* Golduck::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Golduck* newPokemon = new Golduck(pos, dir, lv);
	return newPokemon;
}
