#include "stdafx.h"
#include "Bullet_DarkBall.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_DarkBall::Bullet_DarkBall()
{
	anim->SetSprite(TextureKey::BULLET_DARKBALL_01, TextureKey::BULLET_DARKBALL_18);
	anim->SetLoop(true);
	anim->SetDelay(0.05f);

	transform->scale = { 2.f, 2.f, 2.f };

	lifeTime = 6.f;
	stat.moveSpeed = 0.1f;
}

Bullet_DarkBall::~Bullet_DarkBall()
{
}

void Bullet_DarkBall::Update()
{
	Bullet::Update();
	if (IsDead()) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_DARKBOMB_01, TextureKey::BULLET_DARKBOMB_12, 0.05f);
		ObjectManager::AddObject(fx);
		SoundManager::PlayOverlapSound(L"DarkBomb.wav", SoundChannel::MONSTER, 0.5f);
		Camera::GetInstance()->Shake(0.1f);
	}
	if (stat.moveSpeed < 16.f) {
		stat.moveSpeed *= 1.1f;
	}
}

void Bullet_DarkBall::Render()
{
	Bullet::Render();
}

void Bullet_DarkBall::OnCollision(GameObject* target)
{
	Die();
	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_DARKBOMB_01, TextureKey::BULLET_DARKBOMB_12, 0.05f);
	ObjectManager::AddObject(fx);
	SoundManager::PlayOverlapSound(L"DarkBomb.wav", SoundChannel::MONSTER, 0.5f);
	Camera::GetInstance()->Shake(0.1f);
}