#include "stdafx.h"
#include "Bullet_DiagonalEnergyBall.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_DiagonalEnergyBall::Bullet_DiagonalEnergyBall()
{
	anim->SetSprite(TextureKey::BULLET_ENERGY3_06, TextureKey::BULLET_ENERGY3_18);
	anim->SetLoop(true);
	anim->SetDelay(0.05f);

	transform->scale = { 0.3f, 0.3f, 0.3f };

	lifeTime = 5.f;
	stat.moveSpeed = 6.5f;
}

Bullet_DiagonalEnergyBall::~Bullet_DiagonalEnergyBall()
{
}

void Bullet_DiagonalEnergyBall::Update()
{
	Bullet::Update();
	if (IsDead()) {
		Vector3 fxPos = transform->position;
		fxPos.y += 0.2f;
		Effect* fx = Effect::Create(fxPos, transform->scale, TextureKey::BULLET_ENERGY3_19, TextureKey::BULLET_ENERGY3_23, 0.05f);
		ObjectManager::AddObject(fx);
		fx = Effect::Create(fxPos, transform->scale, TextureKey::LUNA_EFFECT_22, TextureKey::LUNA_EFFECT_26, 0.05f);
		ObjectManager::AddObject(fx);
		SoundManager::PlayOverlapSound(L"DarkBomb.wav", SoundChannel::MONSTER, 0.5f);
		Camera::GetInstance()->Shake(0.05f);
	}
}

void Bullet_DiagonalEnergyBall::Render()
{
	Bullet::Render();
}

void Bullet_DiagonalEnergyBall::OnCollision(GameObject* target)
{
	Die();
	Vector3 fxPos = transform->position;
	fxPos.y += 0.2f;
	Effect* fx = Effect::Create(fxPos, transform->scale, TextureKey::BULLET_ENERGY3_19, TextureKey::BULLET_ENERGY3_23, 0.05f);
	ObjectManager::AddObject(fx);
	fx = Effect::Create(fxPos, transform->scale, TextureKey::LUNA_EFFECT_22, TextureKey::LUNA_EFFECT_26, 0.05f);
	ObjectManager::AddObject(fx);
	SoundManager::PlayOverlapSound(L"DarkBomb.wav", SoundChannel::MONSTER, 0.1f);
	Camera::GetInstance()->Shake(0.05f);
}