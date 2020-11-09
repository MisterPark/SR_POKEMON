#include "stdafx.h"
#include "Bullet_RedBall.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_RedBall::Bullet_RedBall()
{
	anim->SetSprite(TextureKey::BULLET_REDBALL1_01, TextureKey::BULLET_REDBALL1_07);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 1.6f;
	stat.moveSpeed = 3.f;
}

Bullet_RedBall::~Bullet_RedBall()
{
}

void Bullet_RedBall::Update()
{
	Bullet::Update();
}

void Bullet_RedBall::Render()
{
	Bullet::Render();
}

void Bullet_RedBall::OnCollision(GameObject* target)
{
	/*Die();*/
}