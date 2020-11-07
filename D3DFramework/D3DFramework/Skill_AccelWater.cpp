#include "stdafx.h"
#include "Skill_AccelWater.h"
#include "Bullet_Bubble2.h"
#include "Effect.h"

Skill_AccelWater::Skill_AccelWater()
{
	coolTime = 0.5f;
	moveStopTime = 0.5f;
}

Skill_AccelWater::~Skill_AccelWater()
{
}

void Skill_AccelWater::InitCoolTime()
{
	maxCoolTime = coolTime = 0.5f;
}

void Skill_AccelWater::InitActiveTime()
{
	activeTime = 0.5f;
}

void Skill_AccelWater::Update()
{
	if (activeTime < 0.1f) {
		Bullet_Bubble2* bullet = dynamic_cast<Bullet_Bubble2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Bubble2>());
		bullet->transform->position = character->transform->position;
		bullet->SetDir(character->direction);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.5f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 2.f);
		}
		activeTime = 0.f;
	}

	CalcActiveTime();
}

Skill* Skill_AccelWater::Create()
{
	Skill* instance = new Skill_AccelWater;

	return instance;
}