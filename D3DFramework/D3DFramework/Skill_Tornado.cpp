#include "stdafx.h"
#include "Skill_Tornado.h"
#include "Bullet_Tornado.h"
#include "Effect.h"

Skill_Tornado::Skill_Tornado()
{
	moveStopTime = 0.7f;
}

Skill_Tornado::~Skill_Tornado()
{
}

void Skill_Tornado::InitCoolTime()
{
	coolTime = 0.7f;
}

void Skill_Tornado::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_Tornado::Update()
{	
	
	Bullet_Tornado* bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Vector3 Dir2 = { -1.f, 0.f, 1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	bullet->SetTeam(character->team);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}


	bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, 1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	bullet->SetTeam(character->team);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}

	bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { -1.f, 0.f, -1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	bullet->SetTeam(character->team);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}

	bullet = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, -1.f };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	bullet->SetTeam(character->team);

	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}

	CalcActiveTime();
}


Skill * Skill_Tornado::Create()
{
	Skill* instance = new Skill_Tornado;

	return instance;
}