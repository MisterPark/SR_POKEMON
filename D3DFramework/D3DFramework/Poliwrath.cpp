#include "stdafx.h"
#include "Poliwrath.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Poliwrath::Poliwrath()
{
	Initialize();
}

Poliwrath::Poliwrath(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Poliwrath::~Poliwrath()
{
}

void Poliwrath::Initialize()
{
	name = L"°­Ã¬ÀÌ";
	SetTexture(State::WALK, TextureKey::WRATH_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::WRATH_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::WRATH_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::WRATH_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::WRATH_ATTACK_D_01, 2);

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

void Poliwrath::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Poliwrath::Render()
{
	Character::Render();
}

void Poliwrath::Release()
{
}

void Poliwrath::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Poliwrath* Poliwrath::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Poliwrath* newPokemon = new Poliwrath(pos, scale, dir);
	return newPokemon;
}