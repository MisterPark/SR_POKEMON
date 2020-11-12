#include "stdafx.h"
#include "Skill_GravityEnergyBall.h"
#include "Bullet_GravityEnergyBall.h"
#include "Effect.h"

Skill_GravityEnergyBall::Skill_GravityEnergyBall()
{
	skillIcon = TextureKey::UI_SKILL_ICON_FIREXCROSSBOMB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_GravityEnergyBall::~Skill_GravityEnergyBall()
{
}

void Skill_GravityEnergyBall::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_GravityEnergyBall::InitActiveTime()
{
	activeTime = 2.f;
}

void Skill_GravityEnergyBall::Update()
{
	if (activeTime > 1.f) {
		activeTime = 1.f;
		SoundManager::PlayOverlapSound(L"DarkraiGravity.wav", SoundChannel::MONSTER);
		Effect* effect = Effect::Create(character->transform->position, character->transform->scale, TextureKey::LUNA_EFFECT_06, TextureKey::LUNA_EFFECT_14, 0.05f);
		ObjectManager::AddObject(effect);
	}
	delay -= TimeManager::DeltaTime();

	if (delay < 0.f) {
		Vector3 bulPos;// = character->transform->position;
		bulPos.x = 4.f + Random::Value(410) * 0.1f;
		bulPos.y = character->transform->position.y + 1.f;
		bulPos.z = 4.f + Random::Value(410) * 0.1f;

		Bullet_GravityEnergyBall* bullet = dynamic_cast<Bullet_GravityEnergyBall*>(ObjectManager::GetInstance()->CreateObject<Bullet_GravityEnergyBall>());
		bullet->transform->position = bulPos;

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			//bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			//bullet->SetInitAttack(character->stat.attack);
		}
		bullet->SetInitAttack(0.f);

		delay = 0.1f;
	}

	CalcActiveTime();
}

Skill* Skill_GravityEnergyBall::Create()
{
	Skill* instance = new Skill_GravityEnergyBall;

	return instance;
}