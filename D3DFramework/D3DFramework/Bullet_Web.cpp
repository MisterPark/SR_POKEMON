#include "stdafx.h"
#include "Bullet_Web.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Bullet_Web::Bullet_Web()
{   //TODO : 불렛이 지형타는중
	anim->SetSprite(TextureKey::BULLET_WEB1_01, TextureKey::BULLET_WEB1_01);
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

    lifeTime = 4.5f;
    moveSpeed = 3.f;
}

Bullet_Web::~Bullet_Web()
{
}

void Bullet_Web::Update()
{
    Bullet::Update();
}

void Bullet_Web::Render()
{
    Bullet::Render();
}

void Bullet_Web::OnCollision(GameObject* target)
{
	isDead = true;
}