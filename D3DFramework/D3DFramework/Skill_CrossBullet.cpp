#include "stdafx.h"
#include "Skill_CrossBullet.h"
#include "Bullet_Poision.h"
#include "Effect.h"

Skill_CrossBullet::Skill_CrossBullet()
{
	coolTime = 0.6f;
}

Skill_CrossBullet::~Skill_CrossBullet()
{
}

void Skill_CrossBullet::Active(const Character* character)
{
	Bullet_Poision* bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Vector3 Dir2 = { character->direction.x,0.f,character->direction.z };
	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { character->direction.z, 0.f, -character->direction.x };
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -character->direction.x, 0.f, -character->direction.z };
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -character->direction.z, 0.f, character->direction.x };
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}

Skill * Skill_CrossBullet::Create()
{
	Skill* instance = new Skill_CrossBullet;

	return instance;
}