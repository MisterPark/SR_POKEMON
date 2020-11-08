#include "stdafx.h"
#include "Skill_FireShot.h"
#include "Bullet_FireShot.h"
#include "Effect.h"

Skill_FireShot::Skill_FireShot()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_FireShot::~Skill_FireShot()
{
}

void Skill_FireShot::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_FireShot::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_FireShot::Update()
{
	Bullet_FireShot* bullet = dynamic_cast<Bullet_FireShot*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireShot>());
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

Skill* Skill_FireShot::Create()
{
	Skill* instance = new Skill_FireShot;

	return instance;
}