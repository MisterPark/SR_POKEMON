#include "stdafx.h"
#include "Skill_IceBullet4.h"
#include "Bullet_Ice2.h"
#include "Effect.h"

Skill_IceBullet4::Skill_IceBullet4()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
}

Skill_IceBullet4::~Skill_IceBullet4()
{
}

void Skill_IceBullet4::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_IceBullet4::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_IceBullet4::Update()
{
	
	Bullet_Ice2* bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ character->direction.x, 0.f, character->direction.z });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ character->direction.z, 0.f, -character->direction.x });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ -character->direction.x, 0.f, -character->direction.z });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}
	
	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ -character->direction.z, 0.f, character->direction.x });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	////

	Vector3 Dir2 = { (character->direction.x + character->direction.z) * 0.5f,  0.5f, (-character->direction.x + character->direction.z) * 0.5f };

	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ Dir2.x, 0.f, Dir2.z });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ Dir2.z, 0.f, -Dir2.x });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ -Dir2.x, 0.f, -Dir2.z });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Ice2*>(ObjectManager::GetInstance()->CreateObject<Bullet_Ice2>());
	bullet->transform->position = character->transform->position;
	bullet->SetDir(Vector3{ -Dir2.z, 0.f, Dir2.x });
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
		CollisionManager::RegisterObject(COLTYPE::ENEMY, bullet);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}


	CalcActiveTime();
}

Skill* Skill_IceBullet4::Create()
{
	Skill* instance = new Skill_IceBullet4;

	return instance;
}