#include "stdafx.h"
#include "Bullet_Water1.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Bullet_Water1::Bullet_Water1()
{   //TODO : 불렛이 지형타는중
	anim->SetSprite(TextureKey::BULLET_WATER1_01, TextureKey::BULLET_WATER1_01);
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 5.f;
    moveSpeed = 6.f;
}

Bullet_Water1::~Bullet_Water1()
{
}

void Bullet_Water1::Update()
{
    Bullet::Update();
}

void Bullet_Water1::Render()
{
    Bullet::Render();
}

void Bullet_Water1::OnCollision(GameObject* target)
{
	isDead = true;
}