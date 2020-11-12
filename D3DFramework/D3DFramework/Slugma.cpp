#include "stdafx.h"
#include "Slugma.h"
#include "Plane.h"
#include "Rectangle.h"

Slugma::Slugma()
{
	Initialize();
}

Slugma::Slugma(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Slugma::~Slugma()
{
}

void Slugma::Initialize()
{
	name = L"마그마그";
	type = TYPE::SLUGMA;
	number = Pokemon::Slugma;

	SetTexture(State::WALK, TextureKey::SLUG_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::SLUG_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SLUG_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SLUG_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SLUG_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.1f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 40;
	defaultMaxHp = 350;

	increaseAttack = defaultAttack * 0.05f;
	increaseMaxHp = defaultMaxHp * 0.05f;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBomb));
	

	SetStatByLevel();
	UpdateAnimation();

}

void Slugma::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Slugma::Render()
{
	Character::Render();
}

void Slugma::Release()
{
}

bool Slugma::Attack(const Vector3& dir, const int& attackType)
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

Slugma* Slugma::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Slugma* newPokemon = new Slugma(pos, dir, lv);
	return newPokemon;
}
