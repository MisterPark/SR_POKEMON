#include "stdafx.h"
#include "Skill_FireXCrossBomb.h"
#include "Bullet_FireMiniBomb.h"
#include "Effect.h"

Skill_FireXCrossBomb::Skill_FireXCrossBomb()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_FireXCrossBomb::~Skill_FireXCrossBomb()
{
}

void Skill_FireXCrossBomb::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_FireXCrossBomb::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_FireXCrossBomb::Update()
{
	Bullet_FireMiniBomb* bullet = dynamic_cast<Bullet_FireMiniBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireMiniBomb>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	bullet->SetInitAttack(character->stat.attack);
	bullet->team = character->team;

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.5f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 2.f);
	}

	CalcActiveTime();
}

Skill* Skill_FireXCrossBomb::Create()
{
	Skill* instance = new Skill_FireXCrossBomb;

	return instance;
}