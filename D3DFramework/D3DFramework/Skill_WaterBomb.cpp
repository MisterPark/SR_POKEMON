#include "stdafx.h"
#include "Skill_WaterBomb.h"
#include "Bullet_WaterBomb.h"
#include "Effect.h"

Skill_WaterBomb::Skill_WaterBomb()
{
	skillIcon = TextureKey::UI_SKILL_ICON_WATERBOMB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_WaterBomb::~Skill_WaterBomb()
{
}

void Skill_WaterBomb::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_WaterBomb::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_WaterBomb::Update()
{
	SoundManager::PlayOverlapSound(L"WaterBomb2.mp3", SoundChannel::PLAYER);
	Bullet_WaterBomb* bullet = dynamic_cast<Bullet_WaterBomb*>(ObjectManager::GetInstance()->CreateObject<Bullet_WaterBomb>());
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

Skill* Skill_WaterBomb::Create()
{
	Skill* instance = new Skill_WaterBomb;

	return instance;
}