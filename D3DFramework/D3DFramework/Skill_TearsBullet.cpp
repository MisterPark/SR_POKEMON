#include "stdafx.h"
#include "Skill_TearsBullet.h"
#include "Bullet_Water.h"
#include "Effect.h"

Skill_TearsBullet::Skill_TearsBullet()
{
	coolTime = 0.4f;
}

Skill_TearsBullet::~Skill_TearsBullet()
{
}

void Skill_TearsBullet::InitActiveTime()
{
}

void Skill_TearsBullet::Update()
{
	Bullet_Water* bullet = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	if (character->team == Team::MONSTERTEAM)
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else if (character->team == Team::PLAYERTEAM)
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	CalcActiveTime();
}

Skill * Skill_TearsBullet::Create()
{
	Skill* instance = new Skill_TearsBullet;

	return instance;
}