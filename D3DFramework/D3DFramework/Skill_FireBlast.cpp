#include "stdafx.h"
#include "Skill_FireBlast.h"
#include "Bullet_FireBlast.h"
#include "Effect.h"

Skill_FireBlast::Skill_FireBlast()
{
	coolTime = 2.f;
	moveStopTime = 2.f;

}

Skill_FireBlast::~Skill_FireBlast()
{
}

void Skill_FireBlast::InitCoolTime()
{
	maxCoolTime = coolTime = 2.f;
}

void Skill_FireBlast::InitActiveTime()
{

	activeTime = 2.5f;
}

void Skill_FireBlast::Update()
{
	if (activeTime > 2.f)
	{
		activeTime = 2.f;
		Effect* fx = Effect::Create(character->transform->position, { 1.f,1.f,1.f }, TextureKey::BULLET_ENERGYBALL2_01, TextureKey::BULLET_ENERGYBALL2_60, 0.01f, false, true);
		fx->transform->position.y -= 0.5f;
		ObjectManager::AddObject(fx);
	}
	
	if (delay <= 0.f) {
		SoundManager::PlaySoundW(L"GroudonBreath.wav", SoundChannel::MONSTER);
		Camera::GetInstance()->Shake(0.05f);
		Bullet_FireBlast* bullet = dynamic_cast<Bullet_FireBlast*>(ObjectManager::GetInstance()->CreateObject<Bullet_FireBlast>());
		bullet->transform->position = character->transform->position;
		bullet->transform->position.y = character->transform->position.y-character->offsetY/2;
		Vector3 rDir = character->direction;
		rDir.x += -0.1f + Random::Value(10) * 0.02f;
		rDir.y += -0.1f + Random::Value(10) * 0.02f;
		rDir.z += -0.1f + Random::Value(10) * 0.02f;
		Vector3::Normalize(&rDir);
		bullet->SetDir(rDir);
		//bullet->SetDir(character->direction);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.005f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack*0.01);
		}
		//delay = 0.2f;
	}
	else {
		delay -= TimeManager::DeltaTime();
	}

	CalcActiveTime();
}

Skill* Skill_FireBlast::Create()
{
	Skill* instance = new Skill_FireBlast;

	return instance;
}