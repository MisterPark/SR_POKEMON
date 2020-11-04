#include "stdafx.h"
#include "Gloom.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Player.h"
#include "Bullet.h"

Gloom::Gloom()
{
	Initialize();
}

Gloom::Gloom(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Gloom::~Gloom()
{
}

void Gloom::Initialize()
{
	name = L"������";
	number = Pokemon::Gloom;

	SetTexture(State::WALK, TextureKey::GLOOM_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::GLOOM_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::GLOOM_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::GLOOM_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::GLOOM_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::CrossBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::XBullet));

	attack = 30;

	hp = 120;
	maxHp = 120;

	UpdateAnimation();
}

void Gloom::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Gloom::Render()
{
	Character::Render();
}

void Gloom::Release()
{
}

bool Gloom::Attack(const Vector3& dir, const int& attackType)
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

Gloom* Gloom::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Gloom* newPokemon = new Gloom(pos, scale, dir);
	return newPokemon;
}