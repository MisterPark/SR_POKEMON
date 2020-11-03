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

Jynx::Jynx(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Jynx::~Jynx()
{
}

void Jynx::Initialize()
{
	name = L"·çÁÖ¶ó";
	SetTexture(State::WALK, TextureKey::JYNX_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::JYNX_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::JYNX_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::JYNX_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::JYNX_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	hp = 500;
	maxHp = 500;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

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

void Jynx::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Jynx* Jynx::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Jynx* newPokemon = new Jynx(pos, scale, dir);
	return newPokemon;
}