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

void Skill_Tornado::InitActiveTime()
{
	// activeTime = 0.7f;
}

void Skill_Tornado::Update()
{

	CalcActiveTime();
}

/*
void Skill_Tornado::Active(const Character* character)
{	
	Bullet_Tornado* b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Vector3 Dir2 = { -1.f, 0.f, 1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;

	b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, 1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;

	b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { -1.f, 0.f, -1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;

	b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
	Dir2 = { 1.f, 0.f, -1.f };
	Dir2.Normalized();
	b->SetDir(Dir2);
	b->transform->position = character->transform->position;
}
*/

Skill * Skill_Tornado::Create()
{
	Skill* instance = new Skill_Tornado;

	return instance;
}