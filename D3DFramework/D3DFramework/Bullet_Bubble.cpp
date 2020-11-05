#include "stdafx.h"
#include "Bullet_Bubble.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Bubble::Bullet_Bubble()
{
	anim->SetSprite(TextureKey::BULLET_BUBBLE1_01, TextureKey::BULLET_BUBBLE1_21);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 1.6f;
	stat.moveSpeed = 3.f;
}

Bullet_Bubble::~Bullet_Bubble()
{
}

void Bullet_Bubble::Update()
{
	Bullet::Update();
	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_BUBBLE1_01, TextureKey::BULLET_BUBBLE1_21, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_Bubble::Render()
{
	Bullet::Render();
}

void Bullet_Bubble::OnCollision(GameObject* target)
{
	isDead = true;
}