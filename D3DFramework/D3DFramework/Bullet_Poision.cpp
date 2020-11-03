#include "stdafx.h"
#include "Bullet_Poision.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Poision::Bullet_Poision()
{   //TODO : 불렛이 지형타는중
	anim->SetSprite(TextureKey::BULLET_POISION1_01, TextureKey::BULLET_POISION1_03);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 2.5f;
	moveSpeed = 1.f;
}

Bullet_Poision::~Bullet_Poision()
{
}

void Bullet_Poision::Update()
{
	Bullet::Update();
	if (lifeTime < 3.2f) {
		anim->SetSprite(TextureKey::BULLET_POISION1_04, TextureKey::BULLET_POISION1_07);
	}
	if (isDead) {
		Effect* effect = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_POISION1_08, TextureKey::BULLET_POISION1_15, 0.05f);
		ObjectManager::AddObject(effect);
	}
}

void Bullet_Poision::Render()
{
	Bullet::Render();
}

void Bullet_Poision::OnCollision(GameObject* target)
{
	isDead = true;
	Effect* effect = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_POISION1_08, TextureKey::BULLET_POISION1_15, 0.05f);
	ObjectManager::AddObject(effect);
}