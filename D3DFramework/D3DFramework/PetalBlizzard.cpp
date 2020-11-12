#include "stdafx.h"
#include "PetalBlizzard.h"
#include "Effect.h"

PetalBlizzard::PetalBlizzard()
{
}

PetalBlizzard::PetalBlizzard(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float att)
{
	transform->position = pos;
	transform->scale = size;
	direction = dir;
	lifeTime = 999.f;

	stat.attack = 0;
	initAttack = att * 2.f;
	stat.moveSpeed = 0.f;

	isOnTerrain = false;

	offsetY = 0.3f;

	readyDieTime = 0.f;
	isDeadAnimation = false;
	isReadyToDie = false;

	Initialize();
}

PetalBlizzard::~PetalBlizzard()
{
}

void PetalBlizzard::Initialize()
{
	int randNum = Random::Range(0, 5);

	startKey = (TextureKey)((int)TextureKey::PETAL_01 + randNum);
	anim->SetSprite(startKey, startKey);
	anim->SetDelay(1.f);
	anim->SetLoop(false);
}

void PetalBlizzard::Update()
{
	Bullet::Update();

	if (!isDeadAnimation)
	{
		stat.moveSpeed = TimeManager::DeltaTime() * 30.f;
		stat.attack = TimeManager::DeltaTime() * initAttack;
	}

	if (TextureKey::PETAL_EXPLOSION_03 == anim->GetCurrentSprite() && !isReadyToDie)
	{
		isReadyToDie = true;
	}

	if (isReadyToDie)
	{
		readyDieTime += TimeManager::DeltaTime();

		if (0.1f >= readyDieTime)
		{
			SoundManager::PlayOverlapSound(L"PetalHit.wav", SoundChannel::EFFECT, 0.3f, 0.3f);
			Die();
		}
	}
}

void PetalBlizzard::Release()
{
}

void PetalBlizzard::OnCollision(GameObject * target)
{
	SoundManager::PlayOverlapSound(L"PetalHit.wav", SoundChannel::EFFECT, 0.3f, 0.3f);
}

void PetalBlizzard::CollideOnTerrain()
{
	if (!isDeadAnimation && isCollideOnTerrain)
	{
		stat.attack = 0.f;
		stat.moveSpeed = 0.f;

		anim->SetSprite(TextureKey::PETAL_EXPLOSION_01, TextureKey::PETAL_EXPLOSION_03);
		anim->SetDelay(0.1f);
		anim->SetTick(0);
		anim->SetLoop(false);

		transform->position.y += 0.1f;
		transform->scale *= 8.f;

		isDeadAnimation = true;
	}
}

PetalBlizzard * PetalBlizzard::Create(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float att)
{
	PetalBlizzard* instance = new PetalBlizzard(pos, size, dir, att);
	return instance;
}