#include "stdafx.h"
#include "Skill_BubbleShot.h"
#include "Bullet_Bubble.h"
#include "Effect.h"

Skill_BubbleShot::Skill_BubbleShot()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_BubbleShot::~Skill_BubbleShot()
{
}

void Skill_BubbleShot::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_BubbleShot::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_BubbleShot::Update()
{
	Bullet_Bubble* bullet = dynamic_cast<Bullet_Bubble*>(ObjectManager::GetInstance()->CreateObject<Bullet_Bubble>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);

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

Skill* Skill_BubbleShot::Create()
{
	Skill* instance = new Skill_BubbleShot;

	return instance;
}