#include "stdafx.h"
#include "Skill_FireBall.h"
#include "PlayerBullet.h"

Skill_FireBall::Skill_FireBall()
{
	skillIcon = TextureKey::BULLET_FIRE_01;
	moveStopTime = 0.4f;
}

Skill_FireBall::~Skill_FireBall()
{
}

void Skill_FireBall::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_FireBall::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_FireBall::Update()
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::FIRE, character->stat.attack);
	ObjectManager::AddObject(bullet);

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

Skill * Skill_FireBall::Create()
{
	Skill* instance = new Skill_FireBall;

	return instance;
}