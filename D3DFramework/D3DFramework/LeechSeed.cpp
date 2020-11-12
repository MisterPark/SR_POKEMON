#include "stdafx.h"
#include "LeechSeed.h"
#include "Effect.h"

LeechSeed::LeechSeed()
{
}

LeechSeed::LeechSeed(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float speed, float _lifeTime, float att)
{
	transform->position = pos;
	transform->scale = size;
	direction = dir;
	direction.y += 0.3f;
	installLifeTime = _lifeTime;
	lifeTime = 99.f;
	stat.attack = att;
	initAttack = att * 1.5f;
	stat.moveSpeed = speed;
	tickTime = 0.f;
	accGravity = 0.f;

	startKey = TextureKey::LEECH_SEED_02;
	endKey = TextureKey::LEECH_SEED_11;

	animDelay = (float)lifeTime / (float(endKey) - float(startKey));

	isOnTerrain = false;

	offsetY = 0.3f;

	anim->SetSprite(TextureKey::LEECH_SEED_01, TextureKey::LEECH_SEED_01);
	anim->SetDelay(0.2f);
	anim->SetLoop(false);

	isInstall = false;
	isEndLifeTime = false;
}

LeechSeed::~LeechSeed()
{
}

void LeechSeed::Initialize()
{
}

void LeechSeed::Update()
{
	Bullet::Update();

	NoInstallUpdate();
	InstallUpdate();
}

void LeechSeed::Release()
{
}

void LeechSeed::OnCollision(GameObject * target)
{
	AddToCollideList(target);

	if (isInstall)
	{
		Vector3 pos = target->transform->position;

		Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::YELLOW_FLASH_01, TextureKey::YELLOW_FLASH_03, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void LeechSeed::CollideOnTerrain()
{
	if (!isInstall && isCollideOnTerrain)
	{
		isInstall = true;
		isOnTerrain = true;
		transform->scale *= 4.f;
		offsetY = transform->scale.y;
		lifeTime = installLifeTime;
		stat.moveSpeed = 0.f;

		collideList.clear();

		anim->SetSprite(startKey, endKey);
		anim->SetDelay(0.1f);
		anim->SetLoop(false);

		SoundManager::PlayOverlapSound(L"SeedGrow.wav", SoundChannel::EFFECT);
	}
}

void LeechSeed::NoInstallUpdate()
{
	if (!isInstall)
	{
		accGravity += TimeManager::DeltaTime() * 0.5f;
		direction.y -= accGravity;
	}
}

void LeechSeed::InstallUpdate()
{
	if (isInstall)
	{
		tickTime += TimeManager::DeltaTime();

		installLifeTime -= TimeManager::DeltaTime();

		if (1.f < tickTime)
		{
			collideList.clear();
			tickTime = 0.f;
		}

		if (1.f > installLifeTime && !isEndLifeTime)
		{
			stat.attack = 0.f;
			isEndLifeTime = true;

			anim->SetSprite(TextureKey::R_LEECH_SEED_01, TextureKey::R_LEECH_SEED_10);
			anim->SetDelay(0.1f);
			anim->SetLoop(false);
		}
	}
}

LeechSeed * LeechSeed::Create(const Vector3 & pos, const Vector3 & size, float att, const Vector3 & dir, float speed, float lifeTime)
{
	LeechSeed* instance = new LeechSeed(pos, size, dir, speed, lifeTime, att);
	return instance;
}