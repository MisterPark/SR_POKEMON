#include "stdafx.h"
#include "Bullet_Ice2.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Ice2::Bullet_Ice2()
{
	anim->SetSprite(TextureKey::BULLET_ICE1_21, TextureKey::BULLET_ICE1_24);
	anim->SetLoop(true);
	anim->SetDelay(0.05f);

	transform->scale = { 1.2f, 1.2f, 1.2f };

	attack = initAttack;
	lifeTime = 25.f;
	moveSpeed = 3.5f;
	isOnTerrain = true;
	offsetY = 1.2f;
}

Bullet_Ice2::~Bullet_Ice2()
{
}

void Bullet_Ice2::Update()
{
	Bullet::Update();


	if (isDead) {
		//Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_14, TextureKey::BULLET_ICE1_20, 0.05f);
		//ObjectManager::AddObject(fx);
	}
	if (transform->position.x < 3.5f || transform->position.x > dfTERRAIN_WIDTH - 3.5f) {
		direction.x *= -1.f;
		direction.z += -1.f + Random::Value(11) * 0.2f;
		Vector3::Normalize(&direction);
	}
	else if (transform->position.z < 3.5f || transform->position.z > dfTERRAIN_HEIGHT - 3.5f) {
		direction.z *= -1.f;
		direction.x += -1.f + Random::Value(11) * 0.2f;
		Vector3::Normalize(&direction);
	}
	else if (lifeTime < 2.f) {
		float decScale = 0.6f * TimeManager::DeltaTime();
		transform->scale.x -= decScale;
		transform->scale.y -= decScale;
		transform->scale.z -= decScale;
	}
}

void Bullet_Ice2::Render()
{
	Bullet::Render();
}

void Bullet_Ice2::OnCollision(GameObject* target)
{
	isDead = true;
}