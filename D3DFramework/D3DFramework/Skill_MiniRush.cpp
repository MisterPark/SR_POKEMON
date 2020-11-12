#include "stdafx.h"
#include "Skill_MiniRush.h"
#include "Effect.h"
#include "XClaw.h"

Skill_MiniRush::Skill_MiniRush()
{
	skillIcon = TextureKey::UI_SKILL_ICON_MINIRUSH;
	moveStopTime = 1.2f;
	isSpawn = false;
}

Skill_MiniRush::~Skill_MiniRush()
{
}

void Skill_MiniRush::InitCoolTime()
{
	maxCoolTime = coolTime = 1.2f;
	isSpawn = false;
	isDetachCamera = false;
}

void Skill_MiniRush::InitActiveTime()
{
	activeTime = 1.3f;
}

void Skill_MiniRush::Update()
{
	if (!isDetachCamera && Team::PLAYERTEAM == character->team)
	{
		Camera::GetInstance()->SetTarget(nullptr);

		isDetachCamera = true;

		Camera::GetInstance()->Shake(1.f);
	}

	if (0.5f > activeTime && 0.4f < activeTime) {
		activeTime = 0.4f;
		SoundManager::PlayOverlapSound(L"MiniRush.wav", SoundChannel::MONSTER);
	}
	else if (0.4f >= activeTime)
	{
		float speed = 10.f;
		character->transform->position.x += character->direction.x * speed * TimeManager::DeltaTime();
		character->transform->position.z += character->direction.z * speed * TimeManager::DeltaTime();

		if (0.1f < activeTime) {
			if (!isSpawn)
			{
				Vector3 pos = character->transform->position;
				Vector3 dir = character->direction;
				float size = 1.f;
				float lifeTime = 0.4f;

				XClaw* instance = XClaw::Create(pos, { size, size, size }, character->stat.attack, dir, speed, lifeTime);
				ObjectManager::AddObject(instance);
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, instance);
					instance->SetInitAttack(character->stat.attack * 0.5f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, instance);
					instance->SetInitAttack(character->stat.attack * 2.f);
				}
				isSpawn = true;
			}
		}
	}

	CalcActiveTime();
}

void Skill_MiniRush::CalcActiveTime()
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

Skill* Skill_MiniRush::Create()
{
	Skill* instance = new Skill_MiniRush;

	return instance;
}