#include "stdafx.h"
#include "Skill_Explosion.h"
#include "Bullet_Explosion.h"
#include "Player.h"
#include "Effect.h"

Skill_Explosion::Skill_Explosion()
{
	skillIcon = TextureKey::UI_SKILL_ICON_EXPLOSION;
	coolTime = 1.f;
	moveStopTime = 1.f;
}

Skill_Explosion::~Skill_Explosion()
{
}

void Skill_Explosion::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_Explosion::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_Explosion::Update()
{
	SoundManager::PlayOverlapSound(L"Redball.wav", SoundChannel::MONSTER);

	Bullet_Explosion* bullet = dynamic_cast<Bullet_Explosion*>(ObjectManager::GetInstance()->CreateObject<Bullet_Explosion>());
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
		bullet->SetInitAttack(character->stat.attack * 0.25);
		bullet->team = Team::MONSTERTEAM;
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 1.f);
		bullet->team = Team::PLAYERTEAM;
	}


	CalcActiveTime();
}

Skill* Skill_Explosion::Create()
{
	Skill* instance = new Skill_Explosion;

	return instance;
}