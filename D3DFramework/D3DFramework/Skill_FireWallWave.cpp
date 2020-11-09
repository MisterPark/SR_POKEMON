#include "stdafx.h"
#include "Skill_FireWallWave.h"
#include "Bullet_FireWallWave.h"
#include "Player.h"
#include "Effect.h"

Skill_FireWallWave::Skill_FireWallWave()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
	
}

Skill_FireWallWave::~Skill_FireWallWave()
{
}

void Skill_FireWallWave::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_FireWallWave::InitActiveTime()
{
	activeTime = 25.f;
}

void Skill_FireWallWave::Update()
{
	patternTime += TimeManager::DeltaTime();
	character->transform->position.x = 23.5f;
	character->transform->position.z = 48.f-5.0f;
	character->direction = { 0.f,0.f,-1.f };
	

	if (Frame[0] == 0)
	{
		for (int i = 2; i < 46; i+=2)
		{
				Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
				bullet->transform->position.x = i;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = 45.f;
				bullet->transform->position.y += 0.23f;

				bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
				float size = 0.5f;
				bullet->transform->scale = { size,size,size };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 2.f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack);
				}
		}
		Frame[0]++;
	}
	else if (Frame[0] == 1 && patternTime > 1.f)
	{
		for (int i = 3; i < 46; i += 2)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}
		Frame[0]++;
	}
	else if (Frame[0] == 2 && patternTime > 1.5f)
	{
		for (int i = 2; i < 46; i += 2)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}
		Frame[0]++;
	}
	else if (Frame[0] == 3 && patternTime > 2.f)
	{
		for (int i = 2; i <20; i++)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}

		for (int i = 26; i < 46; i++)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}

		Frame[0]++;
	}

	else if (Frame[0] == 4 && patternTime > 4.f)
	{
	for (int i = 15; i < 35; i++)
	{
		Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
		bullet->transform->position.x = i;
		bullet->transform->position.y = 0.f;
		bullet->transform->position.z = 45.f;
		bullet->transform->position.y += 0.23f;
 
		bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
		float size = 0.5f;
		bullet->transform->scale = { size,size,size };
		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 2.f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}
	}


	Frame[0]++;
	}

	else if (Frame[0] == 5 && patternTime > 5.5f)
	{
		for (int i = 2; i < 20; i++)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}

		for (int i = 26; i < 46; i++)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}

	Frame[0]++;
	}
	else if (Frame[0] == 6 && patternTime > 5.5f)
	{
	for (int i = 40; i > 5; --i)
	{
		Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
		bullet->transform->position.x = i;
		bullet->transform->position.y = 0.f;
		bullet->transform->position.z = 45.f + i*0.3;
		bullet->transform->position.y += 0.23f;
 
		bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
		float size = 0.5f;
		bullet->transform->scale = { size,size,size };
		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 2.f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}
	}

	Frame[0]++;
	}

	else if (Frame[0] == 7 && patternTime > 9.8f)
	{
		for (int i = 2; i < 20; ++i)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = 46-i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f+i*0.3;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}
		for (int i = 23; i < 43; ++i)
		{
			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
			bullet->transform->position.x = 46 - i;
			bullet->transform->position.y = 0.f;
			bullet->transform->position.z = 45.f + i * 0.3;
			bullet->transform->position.y += 0.23f;
 
			bullet->SetDir(Vector3{ 0.f, 0.f, -1.f });
			float size = 0.5f;
			bullet->transform->scale = { size,size,size };
			if (character->team == Team::MONSTERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack * 2.f);
			}
			else if (character->team == Team::PLAYERTEAM) {
				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
				bullet->SetInitAttack(character->stat.attack);
			}
		}
	Frame[0]++;
	}


	if (patternTime > 25.f)
	{
		Frame[0] = 0;
		patternTime = 0;
	}
	CalcActiveTime();
}

Skill* Skill_FireWallWave::Create()
{
	Skill* instance = new Skill_FireWallWave;

	return instance;
}