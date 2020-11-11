#include "stdafx.h"
#include "Skill_SnowVulcan.h"
#include "Bullet_Ice.h"
#include "Effect.h"

Skill_SnowVulcan::Skill_SnowVulcan()
{
	skillIcon = TextureKey::UI_SKILL_ICON_SNOWVULCAN;
	coolTime = 2.f;
	moveStopTime = 2.f;
}

Skill_SnowVulcan::~Skill_SnowVulcan()
{
}

void Skill_SnowVulcan::InitCoolTime()
{
	maxCoolTime = coolTime = 2.f;
}

void Skill_SnowVulcan::InitActiveTime()
{

	activeTime = 2.f;
}

void Skill_SnowVulcan::Update()
{
	if (delay <= 0.f) {
		Bullet_Ice* bullet = dynamic_cast<Bullet_Ice*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice>());
		bullet->transform->position = character->transform->position;
		Vector3 rDir = character->direction;
		rDir.x += -0.1f + Random::Value(10) * 0.02f;
		rDir.y += -0.1f + Random::Value(10) * 0.02f;
		rDir.z += -0.1f + Random::Value(10) * 0.02f;
		Vector3::Normalize(&rDir);
		bullet->SetDir(rDir);
		//bullet->SetDir(character->direction);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}
		delay = 0.2f;
	}
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_SnowVulcan::Create()
{
	Skill* instance = new Skill_SnowVulcan;

	return instance;
}