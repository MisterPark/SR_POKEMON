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

Oddish::Oddish(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Oddish::~Oddish()
{
}

void Oddish::Initialize()
{
	name = L"¶Ñ¹÷ÃÊ";
	SetTexture(State::WALK, TextureKey::ODDI_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::ODDI_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::ODDI_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::ODDI_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::ODDI_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	hp = 60;
	maxHp = 60;

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

void Oddish::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	if (team == Team::PLAYERTEAM) {
		switch (attackType)
		{
		case 0: ChangeState(State::ATTACK); break;
		case 1: ChangeState(State::ATTACK); break;
		}
	}
}

Oddish* Oddish::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Oddish* newPokemon = new Oddish(pos, scale, dir);
	return newPokemon;
}

void Oddish::OnCollision(GameObject* target)
{
	hp -= target->attack;
	if (hp <= 0.f) isDead = true;
}