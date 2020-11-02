#include "stdafx.h"
#include "Skill_XBullet.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_XBullet::Skill_XBullet()
{
}

Skill_XBullet::~Skill_XBullet()
{
}

void Skill_XBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER);
	ObjectManager::AddObject(bullet);

	Effect* effect = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_05, 0.2f, true);
	ObjectManager::AddObject(effect);
}

Skill * Skill_XBullet::Create()
{
	Skill* instance = new Skill_XBullet;

	return instance;
}