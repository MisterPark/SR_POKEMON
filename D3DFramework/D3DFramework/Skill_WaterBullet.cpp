#include "stdafx.h"
#include "Skill_WaterBullet.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_WaterBullet::Skill_WaterBullet()
{
	coolTime = 0.4f;
}

Skill_WaterBullet::~Skill_WaterBullet()
{
}

void Skill_WaterBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER);
	ObjectManager::AddObject(bullet);

	Effect* effect = Effect::Create(pos, {0.2f, 0.2f, 0.2f}, TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_05, 0.2f, true);
	ObjectManager::AddObject(effect);

	if (character->team==Team::MONSTERTEAM)
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else if (character->team == Team::PLAYERTEAM)
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}

Skill * Skill_WaterBullet::Create()
{
	Skill* instance = new Skill_WaterBullet;

	return instance;
}