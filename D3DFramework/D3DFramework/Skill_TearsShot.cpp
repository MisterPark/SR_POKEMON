#include "stdafx.h"
#include "Skill_TearsShot.h"
#include "Bullet_Water.h"
#include "Effect.h"

Skill_TearsShot::Skill_TearsShot()
{
	skillIcon = TextureKey::UI_SKILL_ICON_TEARS;
	coolTime = 0.4f;
}

Skill_TearsShot::~Skill_TearsShot()
{
}

void Skill_TearsShot::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_TearsShot::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_TearsShot::Update()
{
	SoundManager::PlayOverlapSound(L"TearsShot.wav", SoundChannel::MONSTER);

	Bullet_Water* bullet = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(character->direction);

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

Skill * Skill_TearsShot::Create()
{
	Skill* instance = new Skill_TearsShot;

	return instance;
}