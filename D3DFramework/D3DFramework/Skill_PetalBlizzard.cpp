#include "stdafx.h"
#include "Skill_PetalBlizzard.h"
#include "PetalBlizzard.h"
#include "Effect.h"

Skill_PetalBlizzard::Skill_PetalBlizzard()
{
	skillIcon = TextureKey::ICON_PETALBLIZZARD;
	moveStopTime = 1.f;
	passTime = 0.f;
	isSpawn = false;
}

Skill_PetalBlizzard::~Skill_PetalBlizzard()
{
}

void Skill_PetalBlizzard::InitCoolTime()
{
	maxCoolTime = coolTime = 30.f;
}

void Skill_PetalBlizzard::InitActiveTime()
{
	activeTime = 8.f;
	passTime = 0.f;
	isSpawn = false;
}

void Skill_PetalBlizzard::Update()
{
	if (!isSpawn)
	{
		Vector3 pos = character->transform->position;

		float delay = 1.f / 26.f;
		float offSetY = 0.5f;

		pos.y += offSetY;

		Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::PETAL_EFFECT_01, TextureKey::PETAL_EFFECT_26, delay);
		ObjectManager::AddObject(fx);

		isSpawn = true;
	}

	passTime += TimeManager::DeltaTime();

	if (0.2f >= passTime)
	{
		passTime = 0.f;

		Vector3 pos = character->transform->position;

		float randOffSet = 0.5f;

		float randX = Random::Range(-3.f, 3.f);
		float randY = Random::Range(3.f, 5.f);
		float randZ = Random::Range(-3.f, 3.f);

		pos += { randX, randY, randZ };

		randX = Random::Range(-1.f, 1.f) * randOffSet;
		randZ = Random::Range(-1.f, 1.f) * randOffSet;

		Vector3 dir = { randX, -1.f, randZ };

		D3DXVec3Normalize(&dir, &dir);

		PetalBlizzard* instance = PetalBlizzard::Create(pos, { 0.03f, 0.03f, 0.03f }, dir, character->stat.attack);
		ObjectManager::AddObject(instance);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, instance);
			instance->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, instance);
			instance->SetInitAttack(character->stat.attack);
		}
	}

	CalcActiveTime();
}

Skill * Skill_PetalBlizzard::Create()
{
	Skill* instance = new Skill_PetalBlizzard;

	return instance;
}