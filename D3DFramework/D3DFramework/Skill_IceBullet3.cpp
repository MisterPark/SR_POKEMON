#include "stdafx.h"
#include "Skill_IceBullet3.h"
#include "Bullet_Ice.h"
#include "Effect.h"

Skill_IceBullet3::Skill_IceBullet3()
{
	coolTime = 3.f;
	moveStopTime = 3.f;
}

Skill_IceBullet3::~Skill_IceBullet3()
{
}

void Skill_IceBullet3::InitCoolTime()
{
	maxCoolTime = coolTime = 3.f;
}

void Skill_IceBullet3::InitActiveTime()
{
	activeTime = 3.f;
}

void Skill_IceBullet3::Update()
{
	if (delay <= 0.f) {
		Bullet_Ice* bullet = dynamic_cast<Bullet_Ice*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice>());
		bullet->transform->position = character->transform->position;
		bullet->transform->position.x += character->direction.x * 3.f;
		bullet->transform->position.y += 2.5f;
		bullet->transform->position.z += character->direction.z * 3.f;
		Vector3 Dir = { 0.f, 0.f, 0.f };
		while (Dir.x == 0 && Dir.z == 0) {
			Dir.x = -2.5f + Random::Value(10) * 0.5f;
			Dir.y = 0.f;
			Dir.z = -2.5f + Random::Value(10) * 0.5f;
		}
		bullet->transform->position += Dir;
		Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::RANGE, TextureKey::RANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, {0.f, 0.f, 0.f}, true, 0.1f);
		ObjectManager::AddObject(effect);
		bullet->SetDir(Vector3{0.f, -0.4f, 0.f});
		bullet->attack = character->attack * 3.f;

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->attack);
		}
		delay = 0.05f;
	}
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_IceBullet3::Create()
{
	Skill* instance = new Skill_IceBullet3;

	return instance;
}