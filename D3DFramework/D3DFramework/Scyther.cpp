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

Scyther::Scyther(const Vector3& pos, const Vector3& dir)
{
	transform->position = pos;
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

	SetTexture(State::WALK, TextureKey::SCY_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::READY, TextureKey::SCY_WALK_D_01, 3, 1);
	SetTexture(State::ATTACK, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::SCY_ATTACK_D_01, 2);
	SetTexture(State::SKILL2, TextureKey::SCY_ATTACK_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	stat.moveSpeed = 3.5f;
	offsetY = 1.f;

	
	state = State::READY;

	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Rush));
	skillSet.emplace_back(SkillManager::GetInstance()->GetSkill(SkillName::Tornado));

	transform->scale = { 1.f, 1.f, 1.f };
	stat.attack = 30;
	stat.hp = 700;
	stat.maxHp = 700;

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

void Scyther::ChangeState(State nextState)
{
	if (nextState != state)
	{
		state = nextState;

		AnimSet();
	}
}

void Scyther::AnimSet()
{
	switch (state)
	{
	case State::IDLE:
		anim->SetLoop(false);
		anim->SetDelay(0.1f);
		anim->SetTick(0.f);
		break;
	case State::WALK:
		anim->SetLoop(true);
		anim->SetDelay(0.15f);
		anim->SetTick(0.f);
		break;
	case State::ATTACK:
		anim->SetLoop(false);
		anim->SetDelay(0.2f);
		anim->SetTick(0.f);
		break;
	case State::HURT:
		break;
	}
}

Scyther* Scyther::Create(const Vector3& pos, const Vector3& dir)
{
	Scyther* newPokemon = new Scyther(pos, dir);
	return newPokemon;
}

