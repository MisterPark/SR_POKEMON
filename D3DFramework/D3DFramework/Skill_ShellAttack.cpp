#include "stdafx.h"
#include "Skill_ShellAttack.h"
#include "Bullet_ShortWaterFlow.h"

Skill_ShellAttack::Skill_ShellAttack()
{
	skillIcon = TextureKey::UI_SKILL_ICON_SHELL;
	coolTime = 13.f;
	moveStopTime = 5.f;
}

Skill_ShellAttack::~Skill_ShellAttack()
{
}

void Skill_ShellAttack::InitCoolTime()
{
	maxCoolTime = coolTime = 2.f;
}

void Skill_ShellAttack::InitActiveTime()
{
	activeTime = 6.f; // 2초는 상관없음 사실상 10초
}

void Skill_ShellAttack::Update()
{
	//Ready 부분과 끝나는 부분 처리
	if (activeTime > 5.f) {
		activeTime = 5.f;
		SoundManager::PlayOverlapSound(L"Hydro_Pump.mp3", SoundChannel::PLAYER);
	}

	if (rocateXAdd) {
		rocateX += 0.02f;
		if (rocateX > 1.f) {
			rocateXAdd = false;
		}
	}
	else {
		rocateX -= 0.02f;
		if (rocateX < -1.f) {
			rocateXAdd = true;
		}
	}
	if (rocateZAdd) {
		rocateZ += 0.02f;
		if (rocateZ > 1.f) {
			rocateZAdd = false;
		}
	}
	else {
		rocateZ -= 0.02f;
		if (rocateZ < -1.f) {
			rocateZAdd = true;
		}
	}

	delay -= TimeManager::DeltaTime();
	if (delay < 0.f) {
		Bullet_ShortWaterFlow* bullet = dynamic_cast<Bullet_ShortWaterFlow*>(ObjectManager::GetInstance()->CreateObject<Bullet_ShortWaterFlow>());
		bullet->transform->position = character->transform->position;

		Vector3 Dir2 = { rocateX, 0.f, rocateZ };
		Vector3::Normalize(&Dir2);
		bullet->SetDir(Dir2);
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}

		bullet = dynamic_cast<Bullet_ShortWaterFlow*>(ObjectManager::GetInstance()->CreateObject<Bullet_ShortWaterFlow>());
		bullet->transform->position = character->transform->position;

		Dir2 = { rocateZ, 0.f, -rocateX };
		Vector3::Normalize(&Dir2);
		bullet->SetDir(Dir2);
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}

		bullet = dynamic_cast<Bullet_ShortWaterFlow*>(ObjectManager::GetInstance()->CreateObject<Bullet_ShortWaterFlow>());
		bullet->transform->position = character->transform->position;

		Dir2 = { -rocateX, 0.f, -rocateZ };
		Vector3::Normalize(&Dir2);
		bullet->SetDir(Dir2);
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}

		bullet = dynamic_cast<Bullet_ShortWaterFlow*>(ObjectManager::GetInstance()->CreateObject<Bullet_ShortWaterFlow>());
		bullet->transform->position = character->transform->position;

		Dir2 = { -rocateZ, 0.f, rocateX };
		Vector3::Normalize(&Dir2);
		bullet->SetDir(Dir2);
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}

		delay = 0.1f;
	}

	CalcActiveTime();
}

Skill* Skill_ShellAttack::Create()
{
	Skill* instance = new Skill_ShellAttack;

	return instance;
}