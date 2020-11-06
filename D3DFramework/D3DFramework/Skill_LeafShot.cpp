#include "stdafx.h"
#include "Skill_LeafShot.h"
#include "PlayerBullet.h"

Skill_LeafShot::Skill_LeafShot()
{
	skillIcon = TextureKey::BULLET_LEAF_09;
	moveStopTime = 0.4f;
}

Skill_LeafShot::~Skill_LeafShot()
{
}

void Skill_LeafShot::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_LeafShot::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_LeafShot::Update()
{
	/*if (1)
	{
	Skill_WaterCannon::Create()->Active(character);
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

Skill * Skill_LeafShot::Create()
{
	Skill* instance = new Skill_LeafShot;

	return instance;
}