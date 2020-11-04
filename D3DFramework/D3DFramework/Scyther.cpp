#include "stdafx.h"
#include "Scyther.h"
#include "Rectangle.h"
#include "Bullet_Water.h"
#include "Bullet_Tornado.h"
#include "Player.h"
#include "Bullet.h"

Scyther::Scyther()
{
	Initialize();
}

Scyther::Scyther(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Initialize();
}

Scyther::~Scyther()
{
}

void Scyther::Initialize()
{
	name = L"½º¶óÅ©";
	number = Pokemon::Scyther;

	SetTexture(State::WALK, TextureKey::SCY_WALK_D_02, 3,2);
	SetTexture(State::IDLE, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::SCY_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	moveSpeed = 3.5f;
	offsetY = 1.f;

	

	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Rush));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Tornado));

	hp = 700;
	maxHp = 700;

	UpdateAnimation();
}

void Scyther::Update()
{
	//Parttern();
	Character::Update();

}

void Scyther::Render()
{
	Character::Render();
}

void Scyther::Release()
{
}

bool Scyther::Attack(const Vector3& dir, const int& attackType)
{
	if (Character::Attack(dir, attackType))
	{
		float animDelay = skillSet[attackType]->GetActiveTime();
		animDelay *= 0.85f;

		if (team == Team::PLAYERTEAM) {
			switch (attackType)
			{
			case 0:
				ChangeState(State::ATTACK);
				anim->SetDelay(animDelay);
				anim->SetTick(0.f);
				
				break;
			case 1: ChangeState(State::ATTACK); break;
			}
		}
		return true;
	}
	return false;
}

Scyther* Scyther::Create(const Vector3& pos, const Vector3& scale, const Vector3& dir)
{
	Scyther* newPokemon = new Scyther(pos, scale, dir);
	return newPokemon;
}

