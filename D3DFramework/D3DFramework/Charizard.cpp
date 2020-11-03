#include "stdafx.h"
#include "Charmander.h"
#include "PlayerBullet.h"

Charmander::Charmander()
{
	Initialize();
}

Charmander::Charmander(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Charmander::~Charmander()
{
}

void Charmander::Initialize()
{
	name = L"ÆÄÀÌ¸®";
	SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF01_WALK_D_01, 3);
	SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	offsetY = 0.13f;

	state = State::IDLE;

	skillSet.reserve(2);

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::FireBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Blaze));

	UpdateAnimation();
}

void Charmander::Update()
{
	Character::Update();
}

void Charmander::Render()
{
	Character::Render();
}

void Charmander::Release()
{
}

void Charmander::Attack(const Vector3 & dir, const int & attackType)
{
	if (skillSet.size() <= attackType) return;
	Vector3 pos = transform->position;

	skillSet[attackType]->Active(this);

	switch (attackType)
	{
	case 0: ChangeState(State::ATTACK); break;
	case 1: ChangeState(State::ATTACK); break;
	}
}

Charmander * Charmander::Create(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir)
{
	Charmander* newPokemon = new Charmander(pos, scale, dir);
	return newPokemon;
}
