#include "stdafx.h"
#include "Skill_WebBullet.h"
#include "Bullet_Web.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_WebBullet::Skill_WebBullet()
{
}

Skill_WebBullet::~Skill_WebBullet()
{
}

void Skill_WebBullet::InitActiveTime()
{
}

void Skill_WebBullet::Update()
{
	CalcActiveTime();
}

/*
void Skill_WebBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER);
	ObjectManager::AddObject(bullet);

	Effect* effect = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_05, 0.2f, true);
	ObjectManager::AddObject(effect);
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}
*/

Skill * Skill_WebBullet::Create()
{
	Skill* instance = new Skill_WebBullet;

	return instance;
}