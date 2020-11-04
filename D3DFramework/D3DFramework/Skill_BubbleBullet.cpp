#include "stdafx.h"
#include "Skill_BubbleBullet.h"
#include "Bullet_Bubble.h"
#include "Effect.h"

Skill_BubbleBullet::Skill_BubbleBullet()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_BubbleBullet::~Skill_BubbleBullet()
{
}

void Skill_BubbleBullet::InitCoolTime()
{
	coolTime = 0.4f;
}

void Skill_BubbleBullet::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_BubbleBullet::Update()
{
	Bullet_Bubble* bullet = dynamic_cast<Bullet_Bubble*>(ObjectManager::GetInstance()->CreateObject<Bullet_Bubble>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	bullet->SetInitAttack(character->attack);
	if (character->team == Team::MONSTERTEAM)
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else if (character->team == Team::PLAYERTEAM)
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	CalcActiveTime();
}

Skill* Skill_BubbleBullet::Create()
{
	Skill* instance = new Skill_BubbleBullet;

	return instance;
}