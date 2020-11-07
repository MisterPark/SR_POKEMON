#include "stdafx.h"
#include "Bullet_FireWallWave.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_FireWallWave::Bullet_FireWallWave()
{
	anim->SetSprite(TextureKey::BULLET_INVISIBLE_01, TextureKey::BULLET_INVISIBLE_01);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 4.f;
	stat.moveSpeed = 3.f;

}

Bullet_FireWallWave::~Bullet_FireWallWave()
{
}

void Bullet_FireWallWave::Update()
{
	Bullet::Update();
	if (lifeTime > 3.f) {
		stat.moveSpeed = 0.f;
	}
	else {
		anim->SetSprite(TextureKey::BULLET_INVISIBLE_01, TextureKey::BULLET_INVISIBLE_01);
		stat.moveSpeed = 8.f;
	}

}

void Bullet_FireWallWave::Render()
{
	Bullet::Render();
}

void Bullet_FireWallWave::OnCollision(GameObject* target)
{
	stack++;
	if (stack > 50)
	{
		Die();
	}
}