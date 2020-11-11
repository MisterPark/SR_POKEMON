#include "stdafx.h"
#include "Skill_FireBomb.h"
#include "Bullet_FireBomb.h"
#include "Effect.h"

Skill_FireBomb::Skill_FireBomb()
{
	skillIcon = TextureKey::UI_SKILL_ICON_FIREBOMB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_FireBomb::~Skill_FireBomb()
{
}

void Skill_FireBomb::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_FireBomb::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_FireBomb::Update()
{
	Bullet_FireBomb* bullet = dynamic_cast<Bullet_FireBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireBomb>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	bullet->SetInitAttack(character->stat.attack);
	bullet->team = character->team;

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.5f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 2.f);
	}

	CalcActiveTime();
}

Skill* Skill_FireBomb::Create()
{
	Skill* instance = new Skill_FireBomb;

	return instance;
}