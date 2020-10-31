#include "stdafx.h"
#include "BulletLeaf.h"
// Example�� ���� PlayerBullet
#include "PlayerBullet.h"

BulletLeaf::BulletLeaf()
{
}

BulletLeaf::~BulletLeaf()
{
}

void BulletLeaf::Active(const Vector3& pos, const Vector3& dir)
{
	// ��ų ��� �� ������ ����Ʈ�� �浹ü ���
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::LEAF);
	ObjectManager::AddObject(bullet);
}

Skill * BulletLeaf::Create()
{
	Skill* instance = new BulletLeaf;

	return instance;
}