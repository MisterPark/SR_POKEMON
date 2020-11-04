#include "stdafx.h"
#include "Skill_IceBullet.h"
#include "Bullet_Ice.h"
#include "Effect.h"

Skill_IceBullet::Skill_IceBullet()
{
	coolTime = 2.f;
	moveStopTime = 2.f;
}

Skill_IceBullet::~Skill_IceBullet()
{
}

void Skill_IceBullet::InitCoolTime()
{
	coolTime = 2.f;
}

void Skill_IceBullet::InitActiveTime()
{
	activeTime = 2.f;
}

void Skill_IceBullet::Update()
{
	if (delay <= 0.f) {
		Bullet_Ice* bullet = dynamic_cast<Bullet_Ice*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice>());
		Vector3 Dir = { 0.f, 0.f, 0.f };
		while (Dir.x == 0 && Dir.z == 0) {
			Dir.x = -5.f + Random::Value(10) * 1.f;
			Dir.y = -2.5f;
			Dir.z = -5.f + Random::Value(10) * 1.f;
		}
		Vector3::Normalize(&Dir);
		bullet->transform->position = character->transform->position;
		bullet->transform->position.x += Dir.x * 0.1f;
		bullet->transform->position.y += 1.f;
		bullet->transform->position.z += Dir.z * 0.1f;
		bullet->SetDir(Dir);
		bullet->SetInitAttack(character->attack * 2);

		if (character->team == Team::MONSTERTEAM)
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		else if (character->team == Team::PLAYERTEAM)
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		delay = 0.02f;
	}
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_IceBullet::Create()
{
	Skill* instance = new Skill_IceBullet;

	return instance;
}