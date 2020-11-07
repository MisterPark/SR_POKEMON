#include "stdafx.h"
#include "Skill_FireWallWave.h"
#include "Bullet_FireWallWave.h"
#include "Player.h"
#include "Effect.h"

Skill_FireWallWave::Skill_FireWallWave()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
	bulletDir = { 0.f,0.f,0.f };
}

Skill_FireWallWave::~Skill_FireWallWave()
{
}

void Skill_FireWallWave::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_FireWallWave::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_FireWallWave::Update()
{

	Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
	bullet->transform->position = character->transform->position;
	bullet->transform->position.y += 5.f;

	bulletDir.x = bullet->transform->position.x;
	bulletDir.y = 0.f;
	bulletDir.z = bullet->transform->position.z;
	create = true;



	bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
	bullet->stat.attack = character->stat.attack * -3.f;
	bullet->transform->scale = { 0.3f,0.3f,0.3f };
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * -0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * -1.f);
	}

	Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::RANGE, TextureKey::RANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
	ObjectManager::AddObject(effect);

	CalcActiveTime();
}

Skill* Skill_FireWallWave::Create()
{
	Skill* instance = new Skill_FireWallWave;

	return instance;
}