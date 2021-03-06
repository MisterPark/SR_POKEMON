#include "stdafx.h"
#include "Skill_SnowRain.h"
#include "Bullet_Ice.h"
#include "Effect.h"

Skill_SnowRain::Skill_SnowRain()
{
	coolTime = 2.f;
	moveStopTime = 2.f;
}

Skill_SnowRain::~Skill_SnowRain()
{
}

void Skill_SnowRain::InitCoolTime()
{
	maxCoolTime = coolTime = 2.f;
}

void Skill_SnowRain::InitActiveTime()
{
	activeTime = 2.5f;
	soundDelay = 2.0f;
}

void Skill_SnowRain::Update()
{
	soundDelay -= TimeManager::DeltaTime();
	if (activeTime > 2.f)
	{
		activeTime = 2.f;
		SoundManager::PlayOverlapSound(L"SnowRain.wav", SoundChannel::MONSTER);
	}
	if (soundDelay < 1.f&&soundDelay>0)
	{
		SoundManager::PlayOverlapSound(L"SnowRain.wav", SoundChannel::MONSTER);
		soundDelay = 0;
	}
	if (delay <= 0.f) {
		Bullet_Ice* bullet = dynamic_cast<Bullet_Ice*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice>());
		Vector3 Dir = { 0.f, 0.f, 0.f };
		while (Dir.x == 0 && Dir.z == 0) {
			Dir.x = -7.5f + Random::Value(10) * 1.5f;
			Dir.y = -2.5f;
			Dir.z = -7.5f + Random::Value(10) * 1.5f;
		}
		Vector3::Normalize(&Dir);
		bullet->transform->position = character->transform->position;
		bullet->transform->position.x += Dir.x * 0.1f;
		bullet->transform->position.y += 1.f;
		bullet->transform->position.z += Dir.z * 0.1f;
		bullet->SetDir(Dir);
		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.5f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 2.f);
		}
		delay = 0.02f;
	}
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_SnowRain::Create()
{
	Skill* instance = new Skill_SnowRain;

	return instance;
}