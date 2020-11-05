#include "stdafx.h"
#include "Skill_IceBullet2.h"
#include "Bullet_Ice.h"
#include "Effect.h"

Skill_IceBullet2::Skill_IceBullet2()
{
	coolTime = 2.f;
	moveStopTime = 2.f;
}

Skill_IceBullet2::~Skill_IceBullet2()
{
}

void Skill_IceBullet2::InitCoolTime()
{
	maxCoolTime = coolTime = 2.f;
}

void Skill_IceBullet2::InitActiveTime()
{
	activeTime = 2.f;
}

void Skill_IceBullet2::Update()
{
	if (delay <= 0.f) {
		Bullet_Ice* bullet = dynamic_cast<Bullet_Ice*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice>());
		bullet->transform->position = character->transform->position;
		bullet->SetDir(character->direction);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->attack);
		}
		delay = 0.1f;
	}
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_IceBullet2::Create()
{
	Skill* instance = new Skill_IceBullet2;

	return instance;
}