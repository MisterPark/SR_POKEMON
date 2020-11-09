#include "stdafx.h"
#include "Skill_WaterFlow.h"
#include "Bullet_WaterFlow.h"
#include "Effect.h"

Skill_WaterFlow::Skill_WaterFlow()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_WaterFlow::~Skill_WaterFlow()
{
}

void Skill_WaterFlow::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_WaterFlow::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_WaterFlow::Update()
{
	Bullet_WaterFlow* bullet = dynamic_cast<Bullet_WaterFlow*>(ObjectManager::GetInstance()->CreateObject<Bullet_WaterFlow>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	bullet->SetInitAttack(character->stat.attack);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	CalcActiveTime();
}

Skill* Skill_WaterFlow::Create()
{
	Skill* instance = new Skill_WaterFlow;

	return instance;
}