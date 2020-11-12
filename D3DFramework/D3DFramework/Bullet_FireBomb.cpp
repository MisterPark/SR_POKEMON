#include "stdafx.h"
#include "Bullet_FireBomb.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_FireBomb::Bullet_FireBomb()
{
	anim->SetSprite(TextureKey::BULLET_FIREBOMB_01, TextureKey::BULLET_FIREBOMB_03);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 2.f;
	stat.moveSpeed = 7.f;
	gravityAccel = -0.02f;

	isOnTerrain = false;

}

Bullet_FireBomb::~Bullet_FireBomb()
{
}

void Bullet_FireBomb::Update()
{
	Bullet::Update();

	transform->position.y -= gravityAccel;
	gravityAccel += 0.05f * TimeManager::DeltaTime();

	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale * 2.f, TextureKey::BULLET_FIREBOMB_04, TextureKey::BULLET_FIREBOMB_12, 0.05f);
		ObjectManager::AddObject(fx);
		SoundManager::PlayOverlapSound(L"FireBomb1.wav", SoundChannel::MONSTER);
		SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
	}


}

void Bullet_FireBomb::Render()
{
	Bullet::Render();
}

void Bullet_FireBomb::OnCollision(GameObject* target)
{
	isDead = true;

	Effect* fx = Effect::Create(transform->position, transform->scale * 2.f, TextureKey::BULLET_FIREBOMB_04, TextureKey::BULLET_FIREBOMB_12, 0.05f);
	ObjectManager::AddObject(fx);
	SoundManager::PlayOverlapSound(L"FireBomb1.wav", SoundChannel::MONSTER);
	SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);

}