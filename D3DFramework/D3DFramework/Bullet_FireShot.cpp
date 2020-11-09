#include "stdafx.h"
#include "Bullet_FireShot.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_FireShot::Bullet_FireShot()
{
	anim->SetSprite(TextureKey::BULLET_FIRE3_02, TextureKey::BULLET_FIRE3_04);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.7f, 0.7f, 0.7f };

	lifeTime = 2.1f;
	stat.moveSpeed = 3.f;
}

Bullet_FireShot::~Bullet_FireShot()
{
}

void Bullet_FireShot::Update()
{
	Bullet::Update();
	if (IsDead()) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_FIRE3_04, TextureKey::BULLET_FIRE3_12, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_FireShot::Render()
{
	Bullet::Render();
}

void Bullet_FireShot::OnCollision(GameObject* target)
{
	Die();
	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_FIRE3_04, TextureKey::BULLET_FIRE3_12, 0.05f);
	ObjectManager::AddObject(fx);
}