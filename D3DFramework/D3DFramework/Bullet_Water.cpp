#include "stdafx.h"
#include "Bullet_Water.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Bullet_Water::Bullet_Water()
{   //TODO : 불렛이 지형타는중
	anim->SetSprite(TextureKey::BULLET_TEARS_01, TextureKey::BULLET_TEARS_01);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

    lifeTime = 4.5f;
    moveSpeed = 3.f;
}

Bullet_Water::~Bullet_Water()
{
}

void Bullet_Water::Update()
{
	Bullet::Update();
}

void Bullet_Water::Render()
{
    Bullet::Render();
}

void Bullet_Water::OnCollision(GameObject* target)
{
	isDead = true;
}