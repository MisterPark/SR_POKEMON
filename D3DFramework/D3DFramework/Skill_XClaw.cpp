#include "stdafx.h"
#include "Skill_XClaw.h"
#include "Effect.h"
#include "XClaw.h"

Skill_XClaw::Skill_XClaw()
{
	skillIcon = TextureKey::ICON_XCLAW;
	moveStopTime = 1.15f;
	isSpawn = false;
}

Skill_XClaw::~Skill_XClaw()
{
}

void Skill_XClaw::InitCoolTime()
{
	maxCoolTime = coolTime = 6.f;
	isSpawn = false;
	isDetachCamera = false;
	isFirstFrame = true;
}

void Skill_XClaw::InitActiveTime()
{
	activeTime = 1.15f;
}

void Skill_XClaw::Update()
{
	if (isFirstFrame)
	{
		SoundManager::PlayOverlapSound(L"XClaw.wav", SoundChannel::PLAYER_EFFECT);

		Vector3 pos = character->transform->position;

		Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_AURA_01, TextureKey::FIRE_AURA_50, 0.015f);
		ObjectManager::AddObject(fx);

		isFirstFrame = false;
	}

	if (!isDetachCamera && Team::PLAYERTEAM == character->team)
	{
		Camera::GetInstance()->SetTarget(nullptr);

		isDetachCamera = true;

		Camera::GetInstance()->Shake(1.f);
	}

	if (0.4f >= activeTime)
	{
		float speed = 20.f;
		character->isInvincible = true;
		character->transform->position.x += character->direction.x * speed * TimeManager::DeltaTime();
		character->transform->position.z += character->direction.z * speed * TimeManager::DeltaTime();

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

void Skill_XClaw::CalcActiveTime()
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
			character->isInvincible = true;
			SetNoneActive();
		}
	}
}

Skill * Skill_XClaw::Create()
{
	Skill* instance = new Skill_XClaw;

	return instance;
}