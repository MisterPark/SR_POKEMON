#include "stdafx.h"
#include "Skill_Tsunami.h"
#include "Bullet_Tsunami.h"
#include "Effect.h"

Skill_Tsunami::Skill_Tsunami()
{
	skillIcon = TextureKey::UI_SKILL_ICON_TSUNAMI;
	coolTime = 25.f;
	moveStopTime = 0.f;
}

Skill_Tsunami::~Skill_Tsunami()
{
}

void Skill_Tsunami::InitCoolTime()
{
	maxCoolTime = coolTime = 25.f;
}

void Skill_Tsunami::InitActiveTime()
{
	activeTime = 8.f;
}

void Skill_Tsunami::Update()
{
	if (activeTime > 7.5f) {
		activeTime = 7.5f;
		SoundManager::PlayOverlapSound(L"Tsunami.wav", SoundChannel::PLAYER_EFFECT);
	}
	delay -= TimeManager::DeltaTime();
	
	if (delay < 0.f) {
		Vector3 pos = Camera::ScreenToWorldPoint(Vector3(dfCLIENT_WIDTH / 2, dfCLIENT_HEIGHT / 2, 1.f));
		Vector3 characterPos = character->transform->position;
		characterPos.y += character->offsetY;
		Vector3 mousedir = pos - characterPos;
		Vector3::Normalize(&mousedir);

		Vector3 Dir2 = character->transform->position;
		float R = float(Random::Value(10));
		Dir2.x += mousedir.z + (mousedir.z * R * 0.1f);
		Dir2.z += -mousedir.x + (mousedir.z * R * 0.1f);

		Bullet_Tsunami* bullet = dynamic_cast<Bullet_Tsunami*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tsunami>());
		bullet->transform->position = Dir2;//character->transform->position;
		//Vector3 Dir2 = { character->direction.x, 0.f, character->direction.z };
		bullet->SetDir(mousedir);
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.125f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.5f);
		}

		Dir2 = character->transform->position;
		R = float(Random::Value(10));
		Dir2.x += -mousedir.z + (mousedir.z * R * 0.1f);
		Dir2.z += mousedir.x + (mousedir.z * R * 0.1f);

		bullet = dynamic_cast<Bullet_Tsunami*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tsunami>());
		bullet->transform->position = Dir2;
		bullet->SetDir(mousedir);
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.0625f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}

		delay = 0.15f;
	}

	CalcActiveTime();
}

Skill* Skill_Tsunami::Create()
{
	Skill* instance = new Skill_Tsunami;

	return instance;
}