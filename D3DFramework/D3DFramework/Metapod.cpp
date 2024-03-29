#include "stdafx.h"
#include "Metapod.h"
#include "Rectangle.h"
#include "Bullet.h"

Metapod::Metapod()
{
	Initialize();
}

Metapod::Metapod(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Metapod::~Metapod()
{
}

void Metapod::Initialize()
{
	name = L"�ܵ���";
	type = TYPE::METAPOD;
	number = Pokemon::Metapod;

	SetTexture(State::WALK, TextureKey::META_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::META_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::META_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::META_ATTACK_D_01, 2, 1);
	SetTexture(State::SKILL, TextureKey::META_ATTACK_D_01, 2, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 0.7f;
	offsetY = 0.5f;

	state = State::READY;


	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 30;
	defaultMaxHp = 110;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	SetStatByLevel();
	UpdateAnimation();
}

void Metapod::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Metapod::Render()
{
	Character::Render();
}

void Metapod::Release()
{
}

bool Metapod::Attack(const Vector3& dir, const int& attackType)
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

Metapod* Metapod::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Metapod* newPokemon = new Metapod(pos, dir, lv);
	return newPokemon;
}
