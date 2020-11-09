#include "stdafx.h"
#include "Skill_RedBall.h"
#include "Bullet_RedBall.h"
#include "Player.h"
#include "Effect.h"

Skill_RedBall::Skill_RedBall()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
}

Skill_RedBall::~Skill_RedBall()
{
}
	
void Skill_RedBall::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_RedBall::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_RedBall::Update()
{

	Bullet_RedBall* bullet = dynamic_cast<Bullet_RedBall*>(ObjectManager::GetInstance()->CreateObject<Bullet_RedBall>());
	bullet->transform->position = character->transform->position;

	Vector3 rDir = character->direction;
	Vector3::Normalize(&rDir);
	bullet->SetDir(rDir);
	/*bullet->SetDir(Vector3{ 0.f, 0.f, 0.f });*/
	bullet->stat.attack = character->stat.attack * 3.f;
	
	float size = 0.3f;
	bullet->transform->scale = { size,size,size };
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.01f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.04f);
	}

	
	CalcActiveTime();
}

Skill* Skill_RedBall::Create()
{
	Skill* instance = new Skill_RedBall;

	return instance;
}