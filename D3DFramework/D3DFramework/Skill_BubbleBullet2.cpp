#include "stdafx.h"
#include "Skill_BubbleBullet2.h"
#include "Bullet_Bubble2.h"
#include "Effect.h"

Skill_BubbleBullet2::Skill_BubbleBullet2()
{
	coolTime = 0.5f;
	moveStopTime = 0.5f;
}

Skill_BubbleBullet2::~Skill_BubbleBullet2()
{
}

void Skill_BubbleBullet2::InitCoolTime()
{
	coolTime = 0.5f;
}

void Skill_BubbleBullet2::InitActiveTime()
{
	activeTime = 0.5f;
}

void Skill_BubbleBullet2::Update()
{
	if (activeTime < 0.1f) {
		Bullet_Bubble2* bullet = dynamic_cast<Bullet_Bubble2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Bubble2>());
		bullet->transform->position = character->transform->position;
		bullet->SetDir(character->direction);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->attack * 0.5f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->attack * 2.f);
		}
		activeTime = 0.f;
	}

	CalcActiveTime();
}

Skill* Skill_BubbleBullet2::Create()
{
	Skill* instance = new Skill_BubbleBullet2;

	return instance;
}