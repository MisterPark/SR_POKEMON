#include "stdafx.h"
#include "Skill_XClaw.h"
#include "Effect.h"
#include "XClaw.h"

Skill_XClaw::Skill_XClaw()
{
	skillIcon = TextureKey::X_CLAW_02;
	moveStopTime = 1.4f;
	isSpawn = false;
}

Skill_XClaw::~Skill_XClaw()
{
}

void Skill_XClaw::InitCoolTime()
{
	coolTime = 6.f;
	isSpawn = false;
}

void Skill_XClaw::InitActiveTime()
{
	activeTime = 1.4f;
}

void Skill_XClaw::Update()
{
	if (0.4f >= activeTime)
	{
		float speed = 15.f;
		character->transform->position.x += character->direction.x * speed * TimeManager::DeltaTime();
		character->transform->position.z += character->direction.z * speed * TimeManager::DeltaTime();

		if (!isSpawn)
		{
			Vector3 pos = character->transform->position;
			Vector3 dir = character->direction;
			float size = 0.4f;
			float lifeTime = 0.4f;

			XClaw* instance = XClaw::Create(pos, { size, size, size }, TextureKey::X_CLAW_01, TextureKey::X_CLAW_08, character->attack, dir, speed, lifeTime);
			ObjectManager::AddObject(instance);
			if (character->team == Team::MONSTERTEAM)
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, instance);
			else if (character->team == Team::PLAYERTEAM)
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, instance);

			isSpawn = true;
		}
	}

	CalcActiveTime();
}

Skill * Skill_XClaw::Create()
{
	Skill* instance = new Skill_XClaw;

	return instance;
}