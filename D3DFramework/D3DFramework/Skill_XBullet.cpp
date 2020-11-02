#include "stdafx.h"
#include "Skill_XBullet.h"
#include "Bullet_Poision.h"
#include "Effect.h"

Skill_XBullet::Skill_XBullet()
{
}

Skill_XBullet::~Skill_XBullet()
{
}

void Skill_XBullet::Active(const Character* character)
{
	float R = 1.f;

	Bullet_Poision* b = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Vector3 Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z -= R;
	Dir2.Normalized();
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;

	b = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;

	b = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;

	b = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;
}

Skill * Skill_XBullet::Create()
{
	Skill* instance = new Skill_XBullet;

	return instance;
}