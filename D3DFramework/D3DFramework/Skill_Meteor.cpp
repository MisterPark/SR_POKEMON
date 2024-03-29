#include "stdafx.h"
#include "Skill_Meteor.h"
#include "Effect.h"
#include "Meteor.h"

Skill_Meteor::Skill_Meteor()
{
	skillIcon = TextureKey::ICON_METEOR;
	moveStopTime = 2.4f;
	isSpawn = false;
	isSpawnFX = false;
}

Skill_Meteor::~Skill_Meteor()
{
}

void Skill_Meteor::InitCoolTime()
{
	maxCoolTime = coolTime = 30.f;
}

void Skill_Meteor::InitActiveTime()
{
	activeTime = 2.2f;
	isSpawn = false;
	isSpawnFX = false;
}

void Skill_Meteor::Update()
{
	if (!isSpawnFX)
	{
		Vector3 pos = character->transform->position;

		pos.y += 0.5f;

		Effect* fx = Effect::Create(pos, { 0.4f, 0.4f, 0.4f }, TextureKey::BULLET_ENERGYBALL2_01, TextureKey::BULLET_ENERGYBALL2_60, 0.03f);
		ObjectManager::AddObject(fx);

		SoundManager::PlayOverlapSound(L"MeteorReady.wav", SoundChannel::EFFECT);

		isSpawnFX = true;
	}

	if (0.2 >= activeTime && !isSpawn)
	{
		isSpawn = true;

		SoundManager::PlayOverlapSound(L"Meteor.wav", SoundChannel::EFFECT);

		for (int i = 0; i < 10; ++i)
		{
			float randX = Random::Range(-1.f, 1.f);
			float randY = Random::Range(7.f, 12.f);
			float randZ = Random::Range(-1.f, 1.f);

			Vector3 ranVec = { randX, randY, randZ };

			Vector3 pos = character->transform->position + ranVec;

			randX = Random::Range(-1.f, 1.f) * 0.5f;
			randZ = Random::Range(-1.f, 1.f) * 0.5f;

			Vector3 dir = { randX, -1.f, randZ };

			Meteor* instance = Meteor::Create(pos, { 0.2f, 0.2f, 0.2f }, dir, character->GetStat().attack);
			instance->SetTeam(character->team);
			ObjectManager::AddObject(instance);

			if (Team::PLAYERTEAM == character->team)
				CollisionManager::GetInstance()->RegisterObject(COLTYPE::PLAYER_ATTACK, instance);
			else if (Team::MONSTERTEAM == character->team)
				CollisionManager::GetInstance()->RegisterObject(COLTYPE::ENEMY_ATTACK, instance);
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
			SetNoneActive();
		}
	}
}

Skill * Skill_Meteor::Create()
{
	Skill* instance = new Skill_Meteor;

	return instance;
}