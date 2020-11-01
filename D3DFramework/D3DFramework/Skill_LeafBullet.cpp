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
	// 스킬 사용 시 생성할 이펙트와 충돌체 등등
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::LEAF);
	ObjectManager::AddObject(bullet);
}

Skill * Skill_LeafBullet::Create()
{
	Skill* instance = new Skill_LeafBullet;

	return instance;
}