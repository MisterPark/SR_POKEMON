#include "stdafx.h"
#include "Arcanine.h"
#include "Rectangle.h"
#include "Bullet.h"

Arcanine::Arcanine()
{
	Initialize();
}

Arcanine::Arcanine(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;

	direction = dir;
	stat.level = lv;
	Initialize();
}

Arcanine::~Arcanine()
{
}

void Arcanine::Initialize()
{
	name = L"À©µð";
	type = TYPE::ARCANINE;
	number = Pokemon::Arcanine;

	SetTexture(State::WALK, TextureKey::ARCA_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::ARCA_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::ARCA_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::ARCA_ATTACK_D_01, 2, 1);
	SetTexture(State::SKILL, TextureKey::ARCA_ATTACK_D_01, 2, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 0.7f;
	offsetY = 0.5f;

	state = State::READY;
	transform->scale = { 0.5f, 0.5f, 0.5f };

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Explosion));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::RedBall));

	defaultAttack = 50;
	defaultMaxHp = 450;

	increaseAttack = defaultAttack * 0.05;
	increaseMaxHp = defaultMaxHp * 0.05;
	stat.money = 10;

	SetStatByLevel();
	UpdateAnimation();
}

void Arcanine::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Arcanine::Render()
{
	Character::Render();
}

void Arcanine::Release()
{
}

bool Arcanine::Attack(const Vector3& dir, const int& attackType)
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

Arcanine* Arcanine::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Arcanine* newPokemon = new Arcanine(pos, dir, lv);
	return newPokemon;
}
