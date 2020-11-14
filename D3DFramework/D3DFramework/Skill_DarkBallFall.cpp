#include "stdafx.h"
#include "Skill_DarkBallFall.h"
#include "Bullet_DarkBall.h"
#include "Effect.h"

Skill_DarkBallFall::Skill_DarkBallFall()
{
	skillIcon = TextureKey::UI_SKILL_ICON_FIREXCROSSBOMB;
	coolTime = 0.4f;
	moveStopTime = 0.4f;
}

Skill_DarkBallFall::~Skill_DarkBallFall()
{
}

void Skill_DarkBallFall::InitCoolTime()
{
	maxCoolTime = coolTime = 0.4f;
}

void Skill_DarkBallFall::InitActiveTime()
{
	activeTime = 6.f;
}

void Skill_DarkBallFall::Update()
{

	delaySound -= TimeManager::DeltaTime();
	delay -= TimeManager::DeltaTime();
	if (delaySound < 0.f) {
		delaySound = 0.2f;
		SoundManager::PlayOverlapSound(L"DarkraiDarkBall.wav", SoundChannel::MONSTER);
	}
	if (delay < 0.f) {
		Vector3 bulPos;// = character->transform->position;
		bulPos.x = 4.f + Random::Value(410) * 0.1f;
		bulPos.y = 12.f;
		bulPos.z = 4.f + Random::Value(410) * 0.1f;

		Bullet_DarkBall* bullet = dynamic_cast<Bullet_DarkBall*>(ObjectManager::GetInstance()->CreateObject<Bullet_DarkBall>());
		bullet->transform->position = bulPos;
		bullet->SetDir(Vector3{0.f, -1.f, 0.f});
		bullet->SetInitAttack(character->stat.attack);

		if (character->team == Team::MONSTERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack * 0.25f);
		}
		else if (character->team == Team::PLAYERTEAM) {
			CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, bullet);
			bullet->SetInitAttack(character->stat.attack);
		}
		Effect* effect = Effect::Create(bullet->transform->position, Vector3{ 1.6f, 1.6f, 1.6f }, TextureKey::BULLET_DARKRANGE_01, TextureKey::BULLET_DARKRANGE_01, 1.5f, true, true, 0.0f, false, 0.0f, false, 0.0f, { 0.f, 0.f, 0.f }, true, 0.1f);
		ObjectManager::AddObject(effect);

		delay = 0.05f;
	}
	CalcActiveTime();
}

Skill* Skill_DarkBallFall::Create()
{
	Skill* instance = new Skill_DarkBallFall;

	return instance;
}