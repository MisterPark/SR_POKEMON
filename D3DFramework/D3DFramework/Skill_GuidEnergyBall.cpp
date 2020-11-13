#include "stdafx.h"
#include "Skill_GuidEnergyBall.h"
#include "Bullet_GuidEnergyBall.h"
#include "Effect.h"

Skill_GuidEnergyBall::Skill_GuidEnergyBall()
{
	skillIcon = TextureKey::UI_SKILL_ICON_FIREXCROSSBOMB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_GuidEnergyBall::~Skill_GuidEnergyBall()
{
}

void Skill_GuidEnergyBall::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_GuidEnergyBall::InitActiveTime()
{
	activeTime = 1.f;
}

void Skill_GuidEnergyBall::Update()
{
	if (activeTime > 0.5f) {
		activeTime = 0.5f;
		SoundManager::PlayOverlapSound(L"DarkraiGude.wav", SoundChannel::MONSTER);
	}
	delay -= TimeManager::DeltaTime();
	if (delay < 0.f) {
		Vector3 bulPos = character->transform->position;
		bulPos.y += 0.3f;

		Bullet_GuidEnergyBall* bullet = dynamic_cast<Bullet_GuidEnergyBall*>(ObjectManager::GetInstance()->CreateObject<Bullet_GuidEnergyBall>());
		bullet->transform->position = bulPos;
		
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}
		

		delay = 0.05f;
	}

	CalcActiveTime();
}

Skill* Skill_GuidEnergyBall::Create()
{
	Skill* instance = new Skill_GuidEnergyBall;

	return instance;
}