#include "stdafx.h"
#include "Growlithe.h"
#include "Rectangle.h"
#include "Bullet.h"

Growlithe::Growlithe()
{
	Initialize();
}

Growlithe::Growlithe(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;

	direction = dir;

	Initialize();
}

Growlithe::~Growlithe()
{
}

void Growlithe::Initialize()
{
	name = L"°¡µð";
	type = TYPE::GROWLITHE;
	number = Pokemon::Growlithe;

	SetTexture(State::WALK, TextureKey::GROW_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::GROW_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::GROW_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::GROW_ATTACK_D_01, 2, 1);
	SetTexture(State::SKILL, TextureKey::GROW_ATTACK_D_01, 2, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 0.7f;
	offsetY = 0.5f;

	state = State::READY;
	transform->scale = { 0.5f, 0.5f, 0.5f };

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::RedBall));

	stat.attack = 30;

	stat.hp = 110;
	stat.maxHp = 110;

	UpdateAnimation();
}

void Growlithe::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Growlithe::Render()
{
	Character::Render();
}

void Growlithe::Release()
{
}

bool Growlithe::Attack(const Vector3& dir, const int& attackType)
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

Growlithe* Growlithe::Create(const Vector3& pos, const Vector3& dir)
{
	Growlithe* newPokemon = new Growlithe(pos, dir);
	return newPokemon;
}
