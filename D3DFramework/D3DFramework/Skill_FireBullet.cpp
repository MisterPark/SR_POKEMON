#include "stdafx.h"
#include "Skill_FireBullet.h"
#include "PlayerBullet.h"

Skill_FireBullet::Skill_FireBullet()
{
}

Skill_FireBullet::~Skill_FireBullet()
{
}

void Skill_FireBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;
	
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::FIRE);
	ObjectManager::AddObject(bullet);

	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}

Skill * Skill_FireBullet::Create()
{
	Skill* instance = new Skill_FireBullet;

	return instance;
}