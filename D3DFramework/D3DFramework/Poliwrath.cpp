#include "stdafx.h"
#include "Poliwrath.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Poliwrath::Poliwrath()
{
	Initialize();
}

Poliwrath::Poliwrath(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Poliwrath::~Poliwrath()
{
}

void Poliwrath::Initialize()
{
	name = L"��ì��";
	type = TYPE::POLIWRATH;
	number = Pokemon::Poliwrath;

	SetTexture(State::WALK, TextureKey::WRATH_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::WRATH_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::WRATH_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::WRATH_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::WRATH_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 35;
	defaultMaxHp = 450;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::ReverseHealBubble));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::HealBubble));

	SetStatByLevel();
	UpdateAnimation();

}

void Poliwrath::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Poliwrath::Render()
{
	Character::Render();
}

void Poliwrath::Release()
{
}

bool Poliwrath::Attack(const Vector3& dir, const int& attackType)
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

Poliwrath* Poliwrath::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Poliwrath* newPokemon = new Poliwrath(pos, dir, lv);
	return newPokemon;
}