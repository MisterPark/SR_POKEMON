#include "stdafx.h"
#include "Skill_CrossBullet.h"
#include "Bullet_Poision.h"
#include "Effect.h"

Skill_CrossBullet::Skill_CrossBullet()
{
	moveStopTime = 0.5f;
}

Skill_CrossBullet::~Skill_CrossBullet()
{
}

void Skill_CrossBullet::InitCoolTime()
{
	maxCoolTime = coolTime = 0.5f;
}

void Skill_CrossBullet::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_CrossBullet::Update()
{
	Bullet_Poision* bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Vector3 Dir2 = { character->direction.x,0.f,character->direction.z };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { character->direction.z, 0.f, -character->direction.x };
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -character->direction.x, 0.f, -character->direction.z };
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->attack);
	}

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -character->direction.z, 0.f, character->direction.x };
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
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

Skill * Skill_CrossBullet::Create()
{
	Skill* instance = new Skill_CrossBullet;

	return instance;
}