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

Oddish::Oddish(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Oddish::~Oddish()
{
}

void Oddish::Initialize()
{
	name = L"�ѹ���";
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


	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 30;
	defaultMaxHp = 100;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;
	
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

Oddish* Oddish::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Oddish* newPokemon = new Oddish(pos, dir, lv);
	return newPokemon;
}
