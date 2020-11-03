#include "stdafx.h"
#include "Butterfree.h"
#include "Bullet_Water.h"
#include "Bullet.h"

Butterfree::Butterfree()
{
	Initialize();
}

Butterfree::Butterfree(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Butterfree::~Butterfree()
{
	
}


void Butterfree::Initialize()
{
	name = L"�����ö���";
	SetTexture(State::WALK, TextureKey::BUTTER_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::BUTTER_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::BUTTER_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::BUTTER_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::BUTTER_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.3f;
	offsetY = 1.2f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	hp = 300;
	maxHp = 300;

	UpdateAnimation();
}

void Butterfree::Update()
{
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Butterfree::Render()
{
	Character::Render();
}

void Butterfree::Release()
{
}

void Butterfree::Attack(const Vector3& dir, const int& attackType)
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

Butterfree* Butterfree::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Butterfree* newPokemon = new Butterfree(pos, scale, dir);
	return newPokemon;
}

void Butterfree::OnCollision(GameObject* target)
{
	hp -= target->attack;
	if (hp <= 0.f) isDead = true;
}