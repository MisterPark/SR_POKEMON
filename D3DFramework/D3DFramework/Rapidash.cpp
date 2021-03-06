#include "stdafx.h"
#include "Rapidash.h"
#include "Plane.h"
#include "Rectangle.h"

Rapidash::Rapidash()
{
	Initialize();
}

Rapidash::Rapidash(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Rapidash::~Rapidash()
{
}

void Rapidash::Initialize()
{
	name = L"���߸�";
	type = TYPE::RAPIDASH;
	number = Pokemon::Rapidash;

	SetTexture(State::WALK, TextureKey::RAPID_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::RAPID_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::RAPID_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::RAPID_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::RAPID_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 2.5f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 50;
	defaultMaxHp = 450;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::MiniRush));
	//skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireShot));

	SetStatByLevel();
	UpdateAnimation();

}

void Rapidash::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Rapidash::Render()
{
	Character::Render();
}

void Rapidash::Release()
{
}

bool Rapidash::Attack(const Vector3& dir, const int& attackType)
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

Rapidash* Rapidash::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Rapidash* newPokemon = new Rapidash(pos, dir, lv);
	return newPokemon;
}
