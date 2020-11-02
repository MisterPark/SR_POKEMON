#include "stdafx.h"
#include "Skill_TearsBullet.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_TearsBullet::Skill_TearsBullet()
{
}

Skill_TearsBullet::~Skill_TearsBullet()
{
}

void Skill_TearsBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER);
	ObjectManager::AddObject(bullet);
}

Skill * Skill_TearsBullet::Create()
{
	Skill* instance = new Skill_TearsBullet;

	return instance;
}