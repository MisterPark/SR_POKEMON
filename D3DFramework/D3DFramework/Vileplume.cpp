#include "stdafx.h"
#include "Vileplume.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"

Vileplume::Vileplume()
{
	Initialize();
}

Vileplume::Vileplume(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
	direction = dir;

	Initialize();
}

Vileplume::~Vileplume()
{
}

void Vileplume::Initialize()
{
	name = L"라플레시아";
	type = TYPE::VILEPLUME;
	number = Pokemon::Vileplume;

	SetTexture(State::WALK, TextureKey::VILE_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::VILE_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::VILE_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::VILE_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::VILE_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::XShot));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::CrossShot));

	transform->scale = { 0.5f, 0.5f, 0.5f };
	stat.attack = 30;
	stat.hp = 160;
	stat.maxHp = 160;

	UpdateAnimation();
}

void Vileplume::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Vileplume::Render()
{
	Character::Render();
}

void Vileplume::Release()
{
}

bool Vileplume::Attack(const Vector3& dir, const int& attackType)
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

Vileplume* Vileplume::Create(const Vector3& pos, const Vector3& dir)
{
	Vileplume* newPokemon = new Vileplume(pos, dir);
	return newPokemon;
}
