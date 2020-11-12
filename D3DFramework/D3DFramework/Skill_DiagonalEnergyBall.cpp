#include "stdafx.h"
#include "Skill_DiagonalEnergyBall.h"
#include "Bullet_DiagonalEnergyBall.h"
#include "Effect.h"

Skill_DiagonalEnergyBall::Skill_DiagonalEnergyBall()
{
	skillIcon = TextureKey::UI_SKILL_ICON_FIREXCROSSBOMB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_DiagonalEnergyBall::~Skill_DiagonalEnergyBall()
{
}

void Skill_DiagonalEnergyBall::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_DiagonalEnergyBall::InitActiveTime()
{
	activeTime = 4.5f;
}

void Skill_DiagonalEnergyBall::Update()
{
	//if (activeTime > 0.5f) {
	//	activeTime = 0.5f;
	//	SoundManager::PlayOverlapSound(L"DarkraiGude.wav", SoundChannel::MONSTER);
	//	SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
	//}
	delay -= TimeManager::DeltaTime();
	delaySound -= TimeManager::DeltaTime();
	if (delaySound < 0.f) {
		if (Random::Value(2) == 1) {
			SoundManager::PlayOverlapSound(L"DarkraiDiagonalEnergyBall1.wav", SoundChannel::MONSTER);
			SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
		}
		else {
			SoundManager::PlayOverlapSound(L"DarkraiDiagonalEnergyBall2.wav", SoundChannel::MONSTER);
			SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
		}
		delaySound = 0.2f;
	}
	if (delay < 0.f) {
		Vector3 bulPos = character->transform->position;
		
		bulPos.x += (Random::Value(20) - 10) * 0.08f * character->direction.z;
		bulPos.y += 1.5f + Random::Value(10) * 0.05f;
		bulPos.z += (Random::Value(10) - 10) * 0.08f * character->direction.x;

		Bullet_DiagonalEnergyBall* bullet = dynamic_cast<Bullet_DiagonalEnergyBall*>(ObjectManager::GetInstance()->CreateObject<Bullet_DiagonalEnergyBall>());
		bullet->transform->position = bulPos;
		float dirX = character->direction.x;
		float dirZ = character->direction.z;
		bullet->SetDir(Vector3{ dirX + ((Random::Value(11) - 5) * dirX * 0.05f), -0.2f - Random::Value(11) * 0.02f, dirZ + ((Random::Value(11) - 5) * dirZ * 0.05f) });
		bullet->SetInitAttack(character->stat.attack);
		if (Random::Value(2) == 1) {
			Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::LUNA_EFFECT_01, TextureKey::LUNA_EFFECT_05, 0.05f);
			ObjectManager::AddObject(effect);
		}
		else {
			Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::LUNA_EFFECT_15, TextureKey::LUNA_EFFECT_21, 0.05f);
			ObjectManager::AddObject(effect);
		}
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

Skill* Skill_DiagonalEnergyBall::Create()
{
	Skill* instance = new Skill_DiagonalEnergyBall;

	return instance;
}