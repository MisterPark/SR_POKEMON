#include "stdafx.h"
#include "Skill_Rush.h"
#include "PlayerBullet.h"
#include "Effect.h"
#include "Bullet_Water.h"

Skill_Rush::Skill_Rush()
{
	moveStopTime = 1.5f;
}

Skill_Rush::~Skill_Rush()
{
}

void Skill_Rush::InitCoolTime()
{
	maxCoolTime = coolTime = 1.5f;
}

void Skill_Rush::InitActiveTime()
{
	activeTime = 2.f;
}

void Skill_Rush::Update()
{
	if (activeTime > 1.5f)
	{
		activeTime = 1.5f;

	}
	if (activeTime < 0.2f) {
		character->transform->position.x += character->direction.x * character->stat.moveSpeed * 15.f * TimeManager::DeltaTime();
		character->transform->position.z += character->direction.z * character->stat.moveSpeed * 15.f * TimeManager::DeltaTime();
	}
	if (activeTime <= 0.05f) {
		SoundManager::PlayOverlapSound(L"ScytherDash.wav", SoundChannel::MONSTER);
		SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
		for (int j = -2; j < 3; j++)
		{
			for (int i = -2; i < 3; i++)
			{
				Bullet_Water* bullet = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
				Vector3 Dir2 = { character->direction.x + j * 0.8f, 0.f, character->direction.z + i * 0.8f };
				Dir2.Normalized();
				bullet->SetDir(Dir2);
				bullet->transform->position = character->transform->position;
				bullet->transform->position.y -= 0.5f;
				bullet->transform->scale.x = 0.7f;
				bullet->transform->scale.y = 0.7f;
				bullet->transform->scale.z = 0.7f;

				if (character->team == Team::MONSTERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack * 0.25f);
				}
				else if (character->team == Team::PLAYERTEAM) {
					CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
					bullet->SetInitAttack(character->stat.attack);
				}
			}
		}
		activeTime = 0;
		
	}

	//if (0.15f < activeTime) {
	//	MovePlayerFollow(15.f);
	//	if (0.15f > activeTime) {
	//		c->state = State::READY;
	//		Time[1] = 0;
	//		//
	//		for (int j = -2; j < 3; j++)
	//		{
	//			for (int i = -2; i < 3; i++)
	//			{
	//				Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	//				Vector3 Dir2 = { c->direction.x + j * 0.8f, 0.f, c->direction.z + i * 0.8f };
	//				Dir2.Normalized();
	//				b->SetDir(Dir2);
	//				*(b->transform) = *c->transform;
	//				b->transform->position.y -= 0.5f;
	//				b->transform->scale.x = 0.7f;
	//				b->transform->scale.y = 0.7f;
	//				b->transform->scale.z = 0.7f;
	//			}
	//		}
	//		c->anim->SetDelay(0.1f);
	//	}
	//}

	CalcActiveTime();
}

Skill * Skill_Rush::Create()
{
	Skill* instance = new Skill_Rush;

	return instance;
}