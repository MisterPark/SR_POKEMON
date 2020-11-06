#include "stdafx.h"
#include "Skill_WaterCannon.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_WaterCannon::Skill_WaterCannon()
{
	skillIcon = TextureKey::BULLET_WATER_01;
	moveStopTime = 0.4f;
}

Skill_WaterCannon::~Skill_WaterCannon()
{
}

void Skill_WaterCannon::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_WaterCannon::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_WaterCannon::Update()
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER, character->stat.attack);
	ObjectManager::AddObject(bullet);

	Effect* effect = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_05, 0.2f, true);
	ObjectManager::AddObject(effect);

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

Skill * Skill_WaterCannon::Create()
{
	Skill* instance = new Skill_WaterCannon;

	return instance;
}