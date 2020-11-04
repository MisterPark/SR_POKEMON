#include "stdafx.h"
#include "Psyduck.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Bullet_Water.h"


Psyduck::Psyduck()
{
	Initialize();
}

Psyduck::Psyduck(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Psyduck::~Psyduck()
{
}

void Psyduck::Initialize()
{
	name = L"°í¶óÆÄ´ö";
	number = Pokemon::Psyduck;

	SetTexture(State::WALK, TextureKey::PSY_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::PSY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::PSY_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::PSY_ATTACK2_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PSY_ATTACK2_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 1.f;
	offsetY = 0.5f;

	state = State::READY;

	attack = 25;

	hp = 150;
	maxHp = 150;
	
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::WaterBullet));

	UpdateAnimation();

}

void Psyduck::Update()
{
	//Pattern();
	Character::Update();
	if (monsterAI != nullptr) monsterAI->Update();
}

void Psyduck::Render()
{
		Character::Render();
}

void Psyduck::Release()
{
}

bool Psyduck::Attack(const Vector3& dir, const int& attackType)
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

Psyduck* Psyduck::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Psyduck* newPokemon = new Psyduck(pos, scale, dir);
	return newPokemon;
}
