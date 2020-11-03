#include "stdafx.h"
#include "Skill_Tornado.h"
#include "Bullet_Tornado.h"
#include "Effect.h"

Skill_Tornado::Skill_Tornado()
{
	coolTime = 0.7f;
}

Skill_Tornado::~Skill_Tornado()
{
}

void Skill_Tornado::Active(const Character* character)
{	
	Bullet_Tornado* bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Vector3 Dir2 = { -1.f, 0.f, 1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);


	bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, 1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { -1.f, 0.f, -1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, -1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}

Skill * Skill_Tornado::Create()
{
	Skill* instance = new Skill_Tornado;

	return instance;
}