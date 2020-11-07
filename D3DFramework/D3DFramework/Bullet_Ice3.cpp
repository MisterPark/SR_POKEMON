#include "stdafx.h"
#include "Bullet_Ice3.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Ice3::Bullet_Ice3()
{
	anim->SetSprite(TextureKey::BULLET_ICE1_06, TextureKey::BULLET_ICE1_11);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 2.6f;
	stat.moveSpeed = 3.f;
}

Bullet_Ice3::~Bullet_Ice3()
{
}

void Bullet_Ice3::Update()
{
	Bullet::Update();

	if (lifeTime > 2.f) {
		stat.moveSpeed = 0.f;
	}
	else {
		anim->SetSprite(TextureKey::BULLET_ICE1_12, TextureKey::BULLET_ICE1_13);
		stat.moveSpeed = 8.f;
	}

	if (IsDead()) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_26, TextureKey::BULLET_ICE1_33, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_Ice3::Render()
{
	Bullet::Render();
}

void Bullet_Ice3::OnCollision(GameObject* target)
{
	Die();
}