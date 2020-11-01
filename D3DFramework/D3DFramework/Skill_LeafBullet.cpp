#include "stdafx.h"
#include "Skill_LeafBullet.h"
#include "PlayerBullet.h"

Skill_LeafBullet::Skill_LeafBullet()
{
}

Skill_LeafBullet::~Skill_LeafBullet()
{
}

void Skill_LeafBullet::Active(const Vector3& pos, const Vector3& dir)
{
	// ��ų ��� �� ������ ����Ʈ�� �浹ü ���
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::LEAF);
	ObjectManager::AddObject(bullet);
}

Skill * Skill_LeafBullet::Create()
{
	Skill* instance = new Skill_LeafBullet;

	return instance;
}