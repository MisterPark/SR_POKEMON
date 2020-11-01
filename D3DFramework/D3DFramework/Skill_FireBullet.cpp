#include "stdafx.h"
#include "Skill_FireBullet.h"
#include "PlayerBullet.h"

Skill_FireBullet::Skill_FireBullet()
{
}

Skill_FireBullet::~Skill_FireBullet()
{
}

void Skill_FireBullet::Active(const Vector3& pos, const Vector3& dir)
{
	// 스킬 사용 시 생성할 이펙트와 충돌체 등등
	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::FIRE);
	ObjectManager::AddObject(bullet);
}

Skill * Skill_FireBullet::Create()
{
	Skill* instance = new Skill_FireBullet;

	return instance;
}