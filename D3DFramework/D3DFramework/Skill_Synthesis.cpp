#include "stdafx.h"
#include "Skill_Synthesis.h"
#include "Bullet_Synthesis.h"
#include "Player.h"
#include "Effect.h"

Skill_Synthesis::Skill_Synthesis()
{
	skillIcon = TextureKey::ICON_SYNTHESIS;
	coolTime = 1.f;
	moveStopTime = 1.f;
}

Skill_Synthesis::~Skill_Synthesis()
{
}

void Skill_Synthesis::InitCoolTime()
{
	coolTime = 1.f;
}

void Skill_Synthesis::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_Synthesis::Update()
{

	Bullet_Synthesis* bullet = dynamic_cast<Bullet_Synthesis*>(ObjectManager::GetInstance()->CreateObject<Bullet_Synthesis>());
	bullet->transform->position = character->transform->position;


	create = true;



	/*bullet->SetDir(Vector3{ 0.f, 0.f, 0.f });*/
	bullet->stat.attack = character->stat.attack * -3.f;
	bullet->transform->scale = { 1.f,1.f,1.f };
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * -0.005f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * -0.02f);
	}

	Effect* effect = Effect::Create(bullet->transform->position, bullet->transform->scale, TextureKey::BULLET_SYNTHESIS_01, TextureKey::BULLET_SYNTHESIS_04, 0.1f, true, false, 1.5f, true, 4.f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.01f);
	
	ObjectManager::AddObject(effect);

	CalcActiveTime();
}

Skill* Skill_Synthesis::Create()
{
	Skill* instance = new Skill_Synthesis;

	return instance;
}