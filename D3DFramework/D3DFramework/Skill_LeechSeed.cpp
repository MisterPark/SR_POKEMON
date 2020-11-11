#include "stdafx.h"
#include "Skill_LeechSeed.h"
#include "LeechSeed.h"
#include "Effect.h"

Skill_LeechSeed::Skill_LeechSeed()
{
	skillIcon = TextureKey::ICON_LEECHSEED;
	moveStopTime = 0.6f;
}

Skill_LeechSeed::~Skill_LeechSeed()
{
}

void Skill_LeechSeed::InitCoolTime()
{
	maxCoolTime = coolTime = 5.f;
}

void Skill_LeechSeed::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_LeechSeed::Update()
{
	SoundManager::PlayOverlapSound(L"LeechSeed.wav", SoundChannel::EFFECT);

	Vector3 pos = character->transform->position;

	for (int i = 0; i < 3; ++i)
	{
		Vector3 dir = character->direction;

		float angle = (30.f * i) - 30.f;

		Matrix rot;
		D3DXMatrixRotationY(&rot, D3DXToRadian(angle));

		D3DXVec3TransformNormal(&dir, &dir, &rot);

		LeechSeed* instance = LeechSeed::Create(pos, { 0.1f, 0.1f, 0.1f }, character->stat.attack, dir, 20.f, 6.f);
		ObjectManager::AddObject(instance);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, instance);
			instance->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, instance);
			instance->SetInitAttack(character->stat.attack);
		}
	}

	CalcActiveTime();
}

Skill * Skill_LeechSeed::Create()
{
	Skill* instance = new Skill_LeechSeed;

	return instance;
}