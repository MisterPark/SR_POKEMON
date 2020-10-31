#include "stdafx.h"
#include "BulletFire.h"
// Example을 위한 PlayerBullet
#include "PlayerBullet.h"

BulletFire::BulletFire()
{
}

BulletFire::~BulletFire()
{
}

void BulletFire::Active(const Vector3& pos, const Vector3& dir)
{
	// 스킬 사용 시 생성할 이펙트와 충돌체 등등
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::FIRE);
	ObjectManager::AddObject(bullet);
}

Skill * BulletFire::Create()
{
	Skill* instance = new BulletFire;

	return instance;
}