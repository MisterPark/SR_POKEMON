#include "stdafx.h"
#include "Skill_LeafBullet.h"
#include "PlayerBullet.h"

Skill_LeafBullet::Skill_LeafBullet()
{
	coolTime = 0.4f;
}

Skill_LeafBullet::~Skill_LeafBullet()
{
}

void Skill_LeafBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::LEAF);
	ObjectManager::AddObject(bullet);

	if (character->team==Team::MONSTERTEAM)
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else if (character->team == Team::PLAYERTEAM)
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}

Skill * Skill_LeafBullet::Create()
{
	Skill* instance = new Skill_LeafBullet;

	return instance;
}