#include "stdafx.h"
#include "Skill_XBullet.h"
#include "Bullet_Poision.h"
#include "Effect.h"

Skill_XBullet::Skill_XBullet()
{
	coolTime = 0.6f;
}

Skill_XBullet::~Skill_XBullet()
{
}

void Skill_XBullet::InitActiveTime()
{
	//activeTime = 0.6f;
}

void Skill_XBullet::Update()
{
	CalcActiveTime();
}

/*
void Skill_XBullet::Active(const Character* character)
{

	float R = 1.f;
	Vector3 Dir3 = { (character->direction.x + character->direction.z) * 0.5f,  0.5f, (-character->direction.x + character->direction.z) * 0.5f };

	Bullet_Poision* bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Vector3 Dir2 = { Dir3.x,0.f, Dir3.z };

	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { Dir3.z, 0.f, -Dir3.x };

	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -Dir3.x, 0.f, -Dir3.z };

	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -Dir3.z,0.f,Dir3.x };

	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
}
*/

Skill * Skill_XBullet::Create()
{
	Skill* instance = new Skill_XBullet;

	return instance;
}