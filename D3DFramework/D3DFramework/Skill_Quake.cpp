#include "stdafx.h"
#include "Skill_Quake.h"
#include "Bullet_Quake.h"
#include "Player.h"
#include "Effect.h"

Skill_Quake::Skill_Quake()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
	patternTime = 0.f;
	bulletDir = { 0.f,0.f,0.f };
}

Skill_Quake::~Skill_Quake()
{
}

void Skill_Quake::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_Quake::InitActiveTime()
{
	activeTime = 4.5f;
}

void Skill_Quake::Update()
{
	patternTime += TimeManager::DeltaTime();
	
	

	if (Frame[0]==0)
	{
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				Bullet_Quake* bullet = dynamic_cast<Bullet_Quake*>(ObjectManager::GetInstance()->CreateObject<Bullet_Quake>());
				bullet->transform->position.x = character->transform->position.x + i;
				bullet->transform->position.y =0.f;
				bullet->transform->position.z = character->transform->position.z + j;
				bullet->transform->position.y += 0.23f;
				//bulletDir.x = bullet->transform->position.x;
				//bulletDir.y = 0.f;
				//bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::ORANGERANGE, TextureKey::ORANGERANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y=-1.f;
				ObjectManager::AddObject(effect);
				effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack *  0.01f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack *  0.04f);
				}
			}
		}
		Frame[0]++;
	}
	else if (Frame[0] == 1 && patternTime > 1.5f)
	{
		//z축 전방
		for (int i = -3; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				Bullet_Quake* bullet = dynamic_cast<Bullet_Quake*>(ObjectManager::GetInstance()->CreateObject<Bullet_Quake>());
				bullet->transform->position.x = character->transform->position.x + i;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = character->transform->position.z + j;
				bullet->transform->position.y += 0.23f;
				bulletDir.x = bullet->transform->position.x;
				bulletDir.y = 0.f;
				bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::ORANGERANGE, TextureKey::ORANGERANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);
				effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
			}
		}
		//z축 후방
		for (int i = -3; i < 4; i++)
		{
			for (int j = -3; j < -1; j++)
			{
				Bullet_Quake* bullet = dynamic_cast<Bullet_Quake*>(ObjectManager::GetInstance()->CreateObject<Bullet_Quake>());
				bullet->transform->position.x = character->transform->position.x + i;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = character->transform->position.z + j;
				bullet->transform->position.y += 0.23f;
				bulletDir.x = bullet->transform->position.x;
				bulletDir.y = 0.f;
				bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::ORANGERANGE, TextureKey::ORANGERANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);
				effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
			}
		}

		//x축 좌측
		for (int i = -3; i < 4; i++)
		{
			for (int j = -3; j < -1; j++)
			{
				Bullet_Quake* bullet = dynamic_cast<Bullet_Quake*>(ObjectManager::GetInstance()->CreateObject<Bullet_Quake>());
				bullet->transform->position.x = character->transform->position.x + j;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = character->transform->position.z + i;
				bullet->transform->position.y += 0.23f;
				bulletDir.x = bullet->transform->position.x;
				bulletDir.y = 0.f;
				bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::ORANGERANGE, TextureKey::ORANGERANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);
				effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
			}
		}
		for (int i = -3; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				Bullet_Quake* bullet = dynamic_cast<Bullet_Quake*>(ObjectManager::GetInstance()->CreateObject<Bullet_Quake>());
				bullet->transform->position.x = character->transform->position.x + j;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = character->transform->position.z + i;
				bullet->transform->position.y += 0.23f;
				bulletDir.x = bullet->transform->position.x;
				bulletDir.y = 0.f;
				bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::ORANGERANGE, TextureKey::ORANGERANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);
				effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
			}
		}
		Frame[0]++;
	}
	else if (Frame[0] == 2 && patternTime > 3.f)
	{
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				Bullet_Quake* bullet = dynamic_cast<Bullet_Quake*>(ObjectManager::GetInstance()->CreateObject<Bullet_Quake>());
				bullet->transform->position.x = character->transform->position.x + i;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = character->transform->position.z + j;
				bullet->transform->position.y += 0.23f;
				bulletDir.x = bullet->transform->position.x;
				bulletDir.y = 0.f;
				bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::ORANGERANGE, TextureKey::ORANGERANGE, 1.f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);
				effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.04f);
				}
			}
		}
		Frame[0]++;
	}
	if (patternTime > 4.5f)
	{
		Frame[0] = 0;
		patternTime = 0;
	}
	CalcActiveTime();
}

Skill* Skill_Quake::Create()
{
	Skill* instance = new Skill_Quake;

	return instance;
}