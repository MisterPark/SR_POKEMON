#include "stdafx.h"
#include "Poliwag.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Poliwag::Poliwag()
{
	Initialize();
}

Poliwag::Poliwag(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	
	Initialize();
}

Poliwag::~Poliwag()
{
}

void Poliwag::Initialize()
{
	// stat
	name = L"¹ßÃ¬ÀÌ";	
	number = Pokemon::Poliwag;

	// anim
	SetTexture(State::WALK, TextureKey::WAG_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::WAG_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::WAG_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::WAG_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::WAG_ATTACK_D_01, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	stat.attack = 30;
	stat.hp = 200;
	stat.maxHp = 200;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::BubbleShot));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::BubbleShot));

	UpdateAnimation();

}

void Poliwag::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Poliwag::Render()
{
	Character::Render();
}

void Poliwag::Release()
{
}

bool Poliwag::Attack(const Vector3& dir, const int& attackType)
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

Poliwag* Poliwag::Create(const Vector3& pos, const Vector3& dir)
{
	Poliwag* newPokemon = new Poliwag(pos, dir);
	return newPokemon;
}

