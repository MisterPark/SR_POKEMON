#include "stdafx.h"
#include "Skill_WebShot.h"
#include "Bullet_Web.h"
#include "Effect.h"

Skill_WebShot::Skill_WebShot()
{
	skillIcon = TextureKey::UI_SKILL_ICON_WEB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_WebShot::~Skill_WebShot()
{
}

void Skill_WebShot::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_WebShot::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_WebShot::Update()
{
	SoundManager::PlayOverlapSound(L"WebShot.wav", SoundChannel::MONSTER);
	SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);

	Bullet_Web* bullet = dynamic_cast<Bullet_Web*>(ObjectManager::GetInstance()->CreateObject<Bullet_Web>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);
	bullet->SetInitAttack(character->stat.attack);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	CalcActiveTime();
}

Skill * Skill_WebShot::Create()
{
	Skill* instance = new Skill_WebShot;

	return instance;
}