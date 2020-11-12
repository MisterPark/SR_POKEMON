#include "stdafx.h"
#include "Skill_SnowFall.h"
#include "Bullet_Ice3.h"
#include "Effect.h"

Skill_SnowFall::Skill_SnowFall()
{
	coolTime = 3.f;
	moveStopTime = 3.f;
}

Skill_SnowFall::~Skill_SnowFall()
{
}

void Skill_SnowFall::InitCoolTime()
{
	maxCoolTime = coolTime = 3.f;
}

void Skill_SnowFall::InitActiveTime()
{
	activeTime = 3.5f;
}

void Skill_SnowFall::Update()
{
	if (activeTime > 3.f)
	{
		activeTime = 3.f;
		SoundManager::PlayOverlapSound(L"SnowFall.wav", SoundChannel::MONSTER);
	}
	if (delay <= 0.f) {
		Camera::GetInstance()->Shake(0.05f);
		Bullet_Ice3* bullet = dynamic_cast<Bullet_Ice3*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice3>());
		bullet->transform->position = character->transform->position;
		bullet->transform->position.x += character->direction.x * 3.f;
		bullet->transform->position.y += 2.5f;
		bullet->transform->position.z += character->direction.z * 3.f;
		Vector3 Dir = { 0.f, 0.f, 0.f };
		while (Dir.x == 0 && Dir.z == 0) {
			Dir.x = -4.f + Random::Value(10) * 0.8f;
			Dir.y = 0.f;
			Dir.z = -4.f + Random::Value(10) * 0.8f;
		}
		bullet->transform->position += Dir;
		Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::RANGE, TextureKey::RANGE, 1.2f, true, true, 0.0f, false, 0.0f, false, 0.0f, {0.f, 0.f, 0.f}, true, 0.1f);
		ObjectManager::AddObject(effect);
		bullet->SetDir(Vector3{0.f, -0.4f, 0.f});
		bullet->stat.attack = character->stat.attack * 3.f;

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
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_SnowFall::Create()
{
	Skill* instance = new Skill_SnowFall;

	return instance;
}