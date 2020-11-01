#include "stdafx.h"
#include "Skill_WaterBullet.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_WaterBullet::Skill_WaterBullet()
{
}

Skill_WaterBullet::~Skill_WaterBullet()
{
}

void Skill_WaterBullet::Active(const Vector3& pos, const Vector3& dir)
{
	// 스킬 사용 시 생성할 이펙트와 충돌체 등등
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER);
	ObjectManager::AddObject(bullet);

	Effect* effect = Effect::Create(pos, {0.2f, 0.2f, 0.2f}, TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_05, 0.2f, true);
	ObjectManager::AddObject(effect);
}

Skill * Skill_WaterBullet::Create()
{
	Skill* instance = new Skill_WaterBullet;

	return instance;
}