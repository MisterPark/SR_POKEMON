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

Gloom::Gloom(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Gloom::~Gloom()
{
}

void Gloom::Initialize()
{
	name = L"³¿»õ²¿";
	type = TYPE::GLOOM;
	number = Pokemon::Gloom;

	SetTexture(State::WALK, TextureKey::GLOOM_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::GLOOM_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::GLOOM_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::GLOOM_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::GLOOM_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::CrossShot));
	

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 30;
	defaultMaxHp = 120;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	SetStatByLevel();
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

Gloom* Gloom::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Gloom* newPokemon = new Gloom(pos, dir, lv);
	return newPokemon;
}
