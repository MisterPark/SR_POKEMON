#include "stdafx.h"
#include "Bullet_Web.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Web::Bullet_Web()
{
	anim->SetSprite(TextureKey::BULLET_WEB1_01, TextureKey::BULLET_WEB1_01);
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

    lifeTime = 1.6f;
    moveSpeed = 3.f;
}

Bullet_Web::~Bullet_Web()
{
}

void Bullet_Web::Update()
{
    Bullet::Update();
	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_WEB1_02, TextureKey::BULLET_WEB1_03, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_Web::Render()
{
    Bullet::Render();
}

void Bullet_Web::OnCollision(GameObject* target)
{
	isDead = true;
}