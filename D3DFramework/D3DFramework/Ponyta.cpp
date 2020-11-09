#include "stdafx.h"
#include "Ponyta.h"
#include "Plane.h"
#include "Rectangle.h"

Ponyta::Ponyta()
{
	Initialize();
}

Ponyta::Ponyta(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	Initialize();
}

Ponyta::~Ponyta()
{
}

void Ponyta::Initialize()
{
	name = L"Æ÷´ÏÅ¸";
	type = TYPE::PONYTA;
	number = Pokemon::Ponyta;

	SetTexture(State::WALK, TextureKey::PONY_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::PONY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::PONY_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::PONY_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PONY_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 2.f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 40;
	defaultMaxHp = 350;

	increaseAttack = defaultAttack * 0.05;
	increaseMaxHp = defaultMaxHp * 0.05;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::MiniRush));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireShot));

	UpdateAnimation();

}

void Ponyta::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Ponyta::Render()
{
	Character::Render();
}

void Ponyta::Release()
{
}

bool Ponyta::Attack(const Vector3& dir, const int& attackType)
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

Ponyta* Ponyta::Create(const Vector3& pos, const Vector3& dir)
{
	Ponyta* newPokemon = new Ponyta(pos, dir);
	return newPokemon;
}
