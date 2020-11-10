#include "stdafx.h"
#include "Poliwhirl.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Poliwhirl::Poliwhirl()
{
	Initialize();
}

Poliwhirl::Poliwhirl(const Vector3& pos, const Vector3& dir,int lv)
{
	transform->position = pos;
	direction = dir;
	stat.level = lv;
	Initialize();
}

Poliwhirl::~Poliwhirl()
{
}

void Poliwhirl::Initialize()
{
	name = L"¼ö·úÃ¬ÀÌ";
	type = TYPE::POLIWHIRL;
	number = Pokemon::Poliwhirl;

	SetTexture(State::WALK, TextureKey::WHIRL_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::WHIRL_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::WHIRL_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::WHIRL_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::WHIRL_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	transform->scale = { 0.5f, 0.5f, 0.5f };
	defaultAttack = 40;
	defaultMaxHp = 300;

	increaseAttack = defaultAttack * 0.05;
	increaseMaxHp = defaultMaxHp * 0.05;
	stat.money = 10;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::HealBubble));

	SetStatByLevel();
	UpdateAnimation();

}

void Poliwhirl::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Poliwhirl::Render()
{
	Character::Render();
}

void Poliwhirl::Release()
{
}

bool Poliwhirl::Attack(const Vector3& dir, const int& attackType)
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

Poliwhirl* Poliwhirl::Create(const Vector3& pos, const Vector3& dir,int lv)
{
	Poliwhirl* newPokemon = new Poliwhirl(pos, dir, lv);
	return newPokemon;
}