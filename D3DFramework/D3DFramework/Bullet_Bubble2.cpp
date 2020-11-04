#include "stdafx.h"
#include "Bullet_Bubble2.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Bubble2::Bullet_Bubble2()
{   
	anim->SetSprite(TextureKey::BULLET_BUBBLE1_12, TextureKey::BULLET_BUBBLE1_14);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 2.6f;
	moveSpeed = 1.f;
}

Bullet_Bubble2::~Bullet_Bubble2()
{
}

void Bullet_Bubble2::Update()
{
	Bullet::Update();
	if (moveSpeed < 15.f) {
		moveSpeed *= 1.1f;
	}

	if (lifeTime < 2.3f) {
		anim->SetSprite(TextureKey::BULLET_BUBBLE1_15, TextureKey::BULLET_BUBBLE1_18);
	}
	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_BUBBLE1_19, TextureKey::BULLET_BUBBLE1_21, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_Bubble2::Render()
{
	Bullet::Render();
}

void Bullet_Bubble2::OnCollision(GameObject* target)
{
	isDead = true;
}