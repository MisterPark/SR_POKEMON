#include "stdafx.h"
#include "Skill_ReverseHealBubble.h"
#include "Bullet_ReverseHealBubble.h"
#include "Player.h"
#include "Effect.h"

Skill_ReverseHealBubble::Skill_ReverseHealBubble()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
	bulletDir = { 0.f,0.f,0.f };
}

Skill_ReverseHealBubble::~Skill_ReverseHealBubble()
{
}

void Skill_ReverseHealBubble::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_ReverseHealBubble::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_ReverseHealBubble::Update()
{
	GameObject* g = ObjectManager::GetInstance()->GetNearestObject<Character>((GameObject*)character, Character::IsNotAlliance);

	if (g == nullptr)
		return;
	Vector3 playerP = g->transform->position;


	Bullet_ReverseHealBubble* bullet = dynamic_cast<Bullet_ReverseHealBubble*>(ObjectManager::GetInstance()->CreateObject<Bullet_ReverseHealBubble>());
	bullet->transform->position = playerP;
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
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::RANGE2, TextureKey::RANGE2, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
	ObjectManager::AddObject(effect);

	CalcActiveTime();
}

Skill* Skill_ReverseHealBubble::Create()
{
	Skill* instance = new Skill_ReverseHealBubble;

	return instance;
}