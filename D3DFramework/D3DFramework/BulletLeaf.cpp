#include "stdafx.h"
#include "BulletLeaf.h"
// Example을 위한 PlayerBullet
#include "PlayerBullet.h"

BulletLeaf::BulletLeaf()
{
}

BulletLeaf::~BulletLeaf()
{
}

void BulletLeaf::Active(const Vector3& pos, const Vector3& dir)
{
	// 스킬 사용 시 생성할 이펙트와 충돌체 등등
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::LEAF);
	ObjectManager::AddObject(bullet);
}

Skill * BulletLeaf::Create()
{
	Skill* instance = new BulletLeaf;

	return instance;
}