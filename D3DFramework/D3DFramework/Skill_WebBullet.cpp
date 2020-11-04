#include "stdafx.h"
#include "Skill_WebBullet.h"
#include "Bullet_Web.h"
#include "Effect.h"

Skill_WebBullet::Skill_WebBullet()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_WebBullet::~Skill_WebBullet()
{
}

void Skill_WebBullet::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_WebBullet::Update()
{
	Bullet_Web* bullet = dynamic_cast<Bullet_Web*>(ObjectManager::GetInstance()->CreateObject<Bullet_Web>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	if (character->team == Team::MONSTERTEAM)
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else if (character->team == Team::PLAYERTEAM)
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	CalcActiveTime();
}

Skill * Skill_WebBullet::Create()
{
	Skill* instance = new Skill_WebBullet;

	return instance;
}