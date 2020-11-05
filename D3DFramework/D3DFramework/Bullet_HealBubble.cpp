#include "stdafx.h"
#include "Bullet_HealBubble.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_HealBubble::Bullet_HealBubble()
{
	anim->SetSprite(TextureKey::BULLET_WATER2_01, TextureKey::BULLET_WATER2_03);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 3.6f;
	stat.moveSpeed = 3.f;

}

Bullet_HealBubble::~Bullet_HealBubble()
{
}

void Bullet_HealBubble::Update()
{
	Bullet::Update();

	if (lifeTime > 3.f) {
		stat.moveSpeed = 0.f;
	}
	else {
		anim->SetSprite(TextureKey::BULLET_WATER2_01, TextureKey::BULLET_WATER2_03);
		stat.moveSpeed = 8.f;
	}

	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_WATER2_01, TextureKey::BULLET_WATER2_03, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_HealBubble::Render()
{
	Bullet::Render();
}

void Bullet_HealBubble::OnCollision(GameObject* target)
{
	isDead = true;
}