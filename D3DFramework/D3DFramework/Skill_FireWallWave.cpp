#include "stdafx.h"
#include "Skill_FireWallWave.h"
#include "Bullet_FireWallWave.h"
#include "Player.h"
#include "Effect.h"

Skill_FireWallWave::Skill_FireWallWave()
{
	coolTime = 1.f;
	moveStopTime = 1.f;
	bulletDir = { 0.f,0.f,0.f };
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
	activeTime = 1.f;
}

void Skill_FireWallWave::Update()
{
	patternTime += TimeManager::DeltaTime();



	if (Frame[0] == 0)
	{
		for (int i = 2; i < 46; i++)
		{
				Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
				bullet->transform->position.x = i;
				bullet->transform->position.y = 0.f;
				bullet->transform->position.z = character->transform->position.z;
				bullet->transform->position.y += 0.23f;
				bulletDir.x = bullet->transform->position.x;
				bulletDir.y = 0.f;
				bulletDir.z = bullet->transform->position.z;
				create = true;
				Effect* effect = Effect::Create(bullet->transform->position,
												bullet->transform->scale, 
												TextureKey::BULLET_FIRE4_01,
												TextureKey::BULLET_FIRE4_13,
												0.1f, 
												false,//플레인?
												true, //빌보드 야?
												0.f, //?
												false, //반복되는이펙트인가
												10.0f, //라이프타임
												true,  //움직임여부
												5.f,//speed
												{ 0.f, 0.f, -1.f },
												true,
												0.5f);
				effect->transform->position.y = -1.f;
				ObjectManager::AddObject(effect);

				bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
				bullet->transform->scale = { 0.3f,0.3f,0.3f };
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
	//else if (Frame[0] == 1 && patternTime > 1.5f)
	//{
	//	//z축 전방
	//	
	//	for (int i = -3; i < 4; i++)
	//	{
	//		for (int j = 2; j < 4; j++)
	//		{
	//			Bullet_FireWallWave* bullet = dynamic_cast<Bullet_FireWallWave*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireWallWave>());
	//			bullet->transform->position.x = character->transform->position.x + j;
	//			bullet->transform->position.y = 0.f;
	//			bullet->transform->position.z = character->transform->position.z + i;
	//			bullet->transform->position.y += 0.23f;
	//			bulletDir.x = bullet->transform->position.x;
	//			bulletDir.y = 0.f;
	//			bulletDir.z = bullet->transform->position.z;
	//			create = true;
	//			Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13, 0.1f, true, true, 1.5f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
	//			effect->transform->position.y = -1.f;
	//			ObjectManager::AddObject(effect);

	//			bullet->SetDir(Vector3{ 0.f, -0.4f, 0.f });
	//			bullet->transform->scale = { 0.3f,0.3f,0.3f };
	//			if (character->team == Team::MONSTERTEAM) {
	//				CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
	//				bullet->SetInitAttack(character->stat.attack * 2.f);
	//			}
	//			else if (character->team == Team::PLAYERTEAM) {
	//				CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
	//				bullet->SetInitAttack(character->stat.attack);
	//			}
	//		}
	//	}
	//	Frame[0]++;
	//}

	if (patternTime > 4.5f)
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