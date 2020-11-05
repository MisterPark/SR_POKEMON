#include "stdafx.h"
#include "Bullet_Water.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Water::Bullet_Water()
{
	anim->SetSprite(TextureKey::BULLET_TEARS_01, TextureKey::BULLET_TEARS_01);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

    lifeTime = 2.f;
    stat.moveSpeed = 3.5f;
}

Bullet_Water::~Bullet_Water()
{
}

void Bullet_Water::Update()
{
	Bullet::Update();

	if (isDead) {
		Effect* effect = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_TEARS_02, TextureKey::BULLET_TEARS_15, 0.05f);
		ObjectManager::AddObject(effect);
	}
}

void Bullet_Water::Render()
{
    Bullet::Render();
}

void Bullet_Water::OnCollision(GameObject* target)
{
	isDead = true;
	Effect* effect = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_TEARS_02, TextureKey::BULLET_TEARS_15, 0.02f);
	ObjectManager::AddObject(effect);
}