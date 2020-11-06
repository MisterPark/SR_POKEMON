#include "stdafx.h"
#include "Bullet_Quake.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Quake::Bullet_Quake()
{
	anim->SetSprite(TextureKey::BULLET_WATERDROP1_01, TextureKey::BULLET_WATERDROP1_01);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 3.6f;
	stat.moveSpeed = 3.f;

}

Bullet_Quake::~Bullet_Quake()
{
}

void Bullet_Quake::Update()
{
	Bullet::Update();
	transform->position.y -= stat.moveSpeed * TimeManager::DeltaTime();
	if (lifeTime > 3.f) {
		stat.moveSpeed = 0.f;
	}
	else {
		anim->SetSprite(TextureKey::BULLET_WATERDROP1_01, TextureKey::BULLET_WATERDROP1_01);
		stat.moveSpeed = 8.f;
	}

}

void Bullet_Quake::Render()
{
	Bullet::Render();
}

void Bullet_Quake::OnCollision(GameObject* target)
{
	isDead = true;
}