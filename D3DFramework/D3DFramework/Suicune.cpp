#include "stdafx.h"
#include "Suicune.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Character.h"

Suicune::Suicune()
{
	Initialize();
}

Suicune::Suicune(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Suicune::~Suicune()
{
}

void Suicune::Initialize()
{
	name = L"½ºÀÌÄï";
	SetTexture(State::WALK, TextureKey::SUI_WALK_D_01, 3);
	SetTexture(State::IDLE, TextureKey::SUI_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SUI_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SUI_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SUI_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	UpdateAnimation();

}

void Suicune::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Suicune::Render()
{
	Character::Render();
}

void Suicune::Release()
{
}

void Suicune::Attack(const Vector3& dir, const int& attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	}
}

Suicune* Suicune::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Suicune* newPokemon = new Suicune(pos, scale, dir);
	return newPokemon;
}