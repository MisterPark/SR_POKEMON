#include "stdafx.h"
#include "Jynx.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Jynx::Jynx()
{
	Initialize();
}

Jynx::Jynx(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Jynx::~Jynx()
{
}

void Jynx::Initialize()
{
	name = L"���ֶ�";
	type = TYPE::JYNX;
	number = Pokemon::Jynx;
	SetTexture(State::WALK, TextureKey::JYNX_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::JYNX_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::JYNX_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::JYNX_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::JYNX_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 30;
	defaultMaxHp = 450;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::SnowVulcan));

	SetStatByLevel();
	UpdateAnimation();

}

void Jynx::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Jynx::Render()
{
	Character::Render();
}

void Jynx::Release()
{
}

bool Jynx::Attack(const Vector3& dir, const int& attackType)
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

Jynx* Jynx::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Jynx* newPokemon = new Jynx(pos, dir, lv);
	return newPokemon;
}