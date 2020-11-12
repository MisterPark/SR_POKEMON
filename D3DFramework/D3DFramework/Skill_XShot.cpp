#include "stdafx.h"
#include "Skill_XShot.h"
#include "Bullet_Poision.h"
#include "Effect.h"

Skill_XShot::Skill_XShot()
{
	skillIcon = TextureKey::UI_SKILL_ICON_XPOISON;
	moveStopTime = 0.5f;
}

Skill_XShot::~Skill_XShot()
{
}

void Skill_XShot::InitCoolTime()
{
	maxCoolTime = coolTime = 0.5f;
}

void Skill_XShot::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_XShot::Update()
{

	SoundManager::PlayOverlapSound(L"GloomAttack.wav", SoundChannel::MONSTER);
	Vector3 Dir3 = { (character->direction.x + character->direction.z) * 0.5f,  0.5f, (-character->direction.x + character->direction.z) * 0.5f };

	Bullet_Poision* bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Vector3 Dir2 = { Dir3.x,0.f, Dir3.z };

	Dir2.Normalized();
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { Dir3.z, 0.f, -Dir3.x };

	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -Dir3.x, 0.f, -Dir3.z };

	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	bullet = dynamic_cast<Bullet_Poision*>(ObjectManager::GetInstance()->CreateObject<Bullet_Poision>());
	Dir2 = { -Dir3.z,0.f,Dir3.x };

	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	bullet->SetDir(Dir2);
	bullet->transform->position = character->transform->position;
	if (character->team == Team::MONSTERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack * 0.25f);
	}
	else if (character->team == Team::PLAYERTEAM) {
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
		bullet->SetInitAttack(character->stat.attack);
	}

	CalcActiveTime();
}

Skill * Skill_XShot::Create()
{
	Skill* instance = new Skill_XShot;

	return instance;
}