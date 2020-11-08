#include "stdafx.h"
#include "Skill_ClawBlast.h"
#include "Effect.h"
#include "XClaw.h"
#include "Bullet_FireBlast.h"
Skill_ClawBlast::Skill_ClawBlast()
{
	skillIcon = TextureKey::BULLET_INVISIBLE_01;
	moveStopTime = 1.4f;
	isSpawn = false;
}

Skill_ClawBlast::~Skill_ClawBlast()
{
}

void Skill_ClawBlast::InitCoolTime()
{
	maxCoolTime = coolTime = 6.f;
	isSpawn = false;
	isDetachCamera = false;
}

void Skill_ClawBlast::InitActiveTime()
{
	activeTime = 1.4f;
}

void Skill_ClawBlast::Update()
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
		Bullet_FireBlast* bullet = dynamic_cast<Bullet_FireBlast*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireBlast>());
		bullet->transform->position = character->transform->position;
		bullet->transform->position.y = character->transform->position.y - character->offsetY / 2;
		Vector3 rDir = character->direction;
		rDir.x += -0.1f + Random::Value(10) * 0.02f;
		rDir.y += -0.1f + Random::Value(10) * 0.02f;
		rDir.z += -0.1f + Random::Value(10) * 0.02f;
		Vector3::Normalize(&rDir);
		bullet->SetDir(rDir);
		//bullet->SetDir(character->direction);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.005f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.01);
		}

		if (!isSpawn)
		{
		
			Vector3 pos = character->transform->position;
			Vector3 dir = character->direction;
			float size = 0.4f;
			float lifeTime = 0.4f;

			XClaw* instance = XClaw::Create(pos, { size, size, size }, character->stat.attack, dir, speed, lifeTime);
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

void Skill_ClawBlast::CalcActiveTime()
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

Skill* Skill_ClawBlast::Create()
{
	Skill* instance = new Skill_ClawBlast;

	return instance;
}