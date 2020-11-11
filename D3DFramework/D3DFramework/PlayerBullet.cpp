#include "stdafx.h"
#include "PlayerBullet.h"
#include "Effect.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::PlayerBullet(const Vector3& pos, const Vector3& dir, const Type& type, const float& att) :
	bulletType(type)
{
	transform->position = pos;
	direction = dir;

	stat.attack = att;
	stat.moveSpeed = 10.f;
	lifeTime = 1.2f;

	animDelay = 0.05f;

	InitByType();
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::InitByType()
{
	switch (bulletType)
	{
	case LEAF:
		transform->scale = { 0.2f, 0.2f, 0.2f };
		anim->SetSprite(TextureKey::BULLET_LEAF_01, TextureKey::BULLET_LEAF_04);
		break;

	case FIRE:
		transform->scale = { 0.2f, 0.2f, 0.2f };
		anim->SetSprite(TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_06);
		SoundManager::PlayOverlapSound(L"FireBall.wav", SoundChannel::EFFECT);
		SoundManager::SetVolume(SoundChannel::EFFECT, 0.3f);
		break;

	case WATER:
		transform->scale = { 0.1f, 0.1f, 0.1f };
		anim->SetSprite(TextureKey::BULLET_WATER_01, TextureKey::BULLET_WATER_02);
		break;
	}

	anim->SetLoop(isLoop);
	anim->SetDelay(animDelay);
}

void PlayerBullet::Update()
{
	if (true == IsDead()) return;

	Bullet::Update();

	CalcLifeTime();
}

void PlayerBullet::Render()
{
	Bullet::Render();
}

void PlayerBullet::OnCollision(GameObject* target)
{
	CollSetByType();
}

void PlayerBullet::CollSetByType()
{
	Die();
	Vector3 pos = transform->position;

	switch (bulletType)
	{
	case PlayerBullet::LEAF:
		SoundManager::PlayOverlapSound(L"LeafShotHit.wav", SoundChannel::EFFECT);
		break;
	case PlayerBullet::FIRE:
	{
		SoundManager::PlayOverlapSound(L"FireExplosion.wav", SoundChannel::EFFECT);
		Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_EXPLOSION_01, TextureKey::FIRE_EXPLOSION_08, 0.03f);
		ObjectManager::AddObject(fx);
		break;
	}
	case PlayerBullet::WATER:
		break;
	}

	SoundManager::PlayOverlapSound(L"Hit.wav", SoundChannel::EFFECT);
	SoundManager::SetVolume(SoundChannel::EFFECT, 0.05f);
}

void PlayerBullet::CalcLifeTime()
{
	lifeTime -= TimeManager::DeltaTime();

	if (lifeTime <= 0.f) Die();
}
