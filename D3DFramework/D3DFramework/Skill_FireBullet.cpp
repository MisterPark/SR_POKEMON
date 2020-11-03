#include "stdafx.h"
#include "Skill_FireBullet.h"
#include "PlayerBullet.h"

Skill_FireBullet::Skill_FireBullet()
{
	coolTime = 0.4f;
}

Skill_FireBullet::~Skill_FireBullet()
{
}

void Skill_FireBullet::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_FireBullet::Update()
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::FIRE);
	ObjectManager::AddObject(bullet);

	if (character->team == Team::MONSTERTEAM)
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else if (character->team == Team::PLAYERTEAM)
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	CalcActiveTime();
}

Skill * Skill_FireBullet::Create()
{
	Skill* instance = new Skill_FireBullet;

	return instance;
}