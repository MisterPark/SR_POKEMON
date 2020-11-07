#include "stdafx.h"
#include "Skill_Meteor.h"
#include "Effect.h"
#include "XClaw.h"

Skill_Meteor::Skill_Meteor()
{
	skillIcon = TextureKey::ICON_XCLAW;
	moveStopTime = 1.4f;
	isSpawn = false;
}

Skill_Meteor::~Skill_Meteor()
{
}

void Skill_Meteor::InitCoolTime()
{
	maxCoolTime = coolTime = 6.f;
	isSpawn = false;
	isDetachCamera = false;
}

void Skill_Meteor::InitActiveTime()
{
	activeTime = 1.4f;
}

void Skill_Meteor::Update()
{
	if (!isDetachCamera && Team::PLAYERTEAM == character->team)
	{
		Camera::GetInstance()->SetTarget(nullptr);

		isDetachCamera = true;

		Camera::GetInstance()->Shake(1.f);
	}

	if (0.4f >= activeTime)
	{
		float speed = 20.f;
		character->transform->position.x += character->direction.x * speed * TimeManager::DeltaTime();
		character->transform->position.z += character->direction.z * speed * TimeManager::DeltaTime();

		if (!isSpawn)
		{
			Vector3 pos = character->transform->position;
			Vector3 dir = character->direction;
			float size = 0.4f;
			float lifeTime = 0.4f;

			XClaw* instance = XClaw::Create(pos, { size, size, size }, TextureKey::X_CLAW_01, TextureKey::X_CLAW_08, character->stat.attack, dir, speed, lifeTime);
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

void Skill_Meteor::CalcActiveTime()
{
	if (isActive)
	{
		activeTime -= TimeManager::DeltaTime();
		if (0.f > activeTime)
		{
			if (isDetachCamera && Team::PLAYERTEAM == character->team)
			{
				Camera::GetInstance()->SlowChaseTarget(character);
				Camera::SetShakeDuration(-1.f);
			}
			SetNoneActive();
		}
	}
}

Skill * Skill_Meteor::Create()
{
	Skill* instance = new Skill_Meteor;

	return instance;
}