#include "stdafx.h"
#include "Skill_HealBubble.h"
#include "Bullet_HealBubble.h"
#include "Player.h"
#include "Effect.h"

Skill_HealBubble::Skill_HealBubble()
{
	coolTime = 0.4f;
	moveStopTime = 0.4f;
	bulletDir = { 0.f,0.f,0.f };
}

Skill_HealBubble::~Skill_HealBubble()
{
}

void Skill_HealBubble::InitCoolTime()
{
	coolTime = 0.4f;
}

void Skill_HealBubble::InitActiveTime()
{
	activeTime =0.f;
}

void Skill_HealBubble::Update()
{

		Bullet_HealBubble* bullet = dynamic_cast<Bullet_HealBubble*>(ObjectManager::GetInstance()->CreateObject<Bullet_HealBubble>());
		if (create == false)
		{
			bullet->transform->position = character->transform->position;
			bullet->transform->position.y += 1.f;
			
			bulletDir.x = bullet->transform->position.x;
			bulletDir.y = 0.f;
			bulletDir.z = bullet->transform->position.z;
			create = true;
		}

		bullet->transform->position += bulletDir;

		Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::RANGE, TextureKey::RANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
		ObjectManager::AddObject(effect);
		bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
		bullet->stat.attack = character->stat.attack * -3.f;

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

Skill* Skill_HealBubble::Create()
{
	Skill* instance = new Skill_HealBubble;

	return instance;
}