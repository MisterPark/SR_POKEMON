#include "stdafx.h"
#include "Skill_LeafBullet.h"
#include "PlayerBullet.h"

Skill_LeafBullet::Skill_LeafBullet()
{
	skillIcon = TextureKey::BULLET_LEAF_09;
	moveStopTime = 0.4f;
}

Skill_LeafBullet::~Skill_LeafBullet()
{
}

void Skill_LeafBullet::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_LeafBullet::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_LeafBullet::Update()
{
	/*if (1)
	{
	Skill_WaterBullet::Create()->Active(character);
	}*/
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::LEAF, character->stat.attack);
	ObjectManager::AddObject(bullet);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	CalcActiveTime();
}

Skill * Skill_LeafBullet::Create()
{
	Skill* instance = new Skill_LeafBullet;

	return instance;
}