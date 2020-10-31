#include "stdafx.h"
#include "BulletFire.h"
// Example�� ���� PlayerBullet
#include "PlayerBullet.h"

BulletFire::BulletFire()
{
}

BulletFire::~BulletFire()
{
}

void BulletFire::Active(const Vector3& pos, const Vector3& dir)
{
	// ��ų ��� �� ������ ����Ʈ�� �浹ü ���
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::FIRE);
	ObjectManager::AddObject(bullet);
}

Skill * BulletFire::Create()
{
	Skill* instance = new BulletFire;

	return instance;
}