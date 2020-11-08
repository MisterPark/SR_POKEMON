#include "stdafx.h"
#include "Bullet_FireMiniBomb.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_FireMiniBomb::Bullet_FireMiniBomb()
{
	anim->SetSprite(TextureKey::BULLET_FIREBOMB_01, TextureKey::BULLET_FIREBOMB_03);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.4f, 0.4f, 0.4f };

	lifeTime = 2.f;
	stat.moveSpeed = 2.5f;
	gravityAccel = -0.02f;

	isOnTerrain = false;

}

Bullet_FireMiniBomb::~Bullet_FireMiniBomb()
{
}

void Bullet_FireMiniBomb::Update()
{
	Bullet::Update();

	transform->position.y -= gravityAccel;
	gravityAccel += 0.05f * TimeManager::DeltaTime();

	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale * 2.f, TextureKey::BULLET_FIREBOMB_04, TextureKey::BULLET_FIREBOMB_12, 0.05f);
		ObjectManager::AddObject(fx);
	}


}

void Bullet_FireMiniBomb::Render()
{
	Bullet::Render();
}

void Bullet_FireMiniBomb::OnCollision(GameObject* target)
{
	isDead = true;

	Effect* fx = Effect::Create(transform->position, transform->scale * 2.f, TextureKey::BULLET_FIREBOMB_04, TextureKey::BULLET_FIREBOMB_12, 0.05f);
	ObjectManager::AddObject(fx);

}