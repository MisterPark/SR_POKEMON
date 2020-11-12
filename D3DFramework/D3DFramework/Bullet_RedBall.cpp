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

	lifeTime = 2.1f;
	stat.moveSpeed = 3.f;
}

Bullet_RedBall::~Bullet_RedBall()
{
}

void Bullet_RedBall::Update()
{
	if (lifeTime>1.6)
	{
		lifeTime = 1.6f;
		SoundManager::PlayOverlapSound(L"Redball.wav", SoundChannel::MONSTER);
		SoundManager::SetVolume(SoundChannel::MONSTER, 0.1f);
	}
	Bullet::Update();
}

void Bullet_RedBall::Render()
{
	Bullet::Render();
}

void Bullet_RedBall::OnCollision(GameObject* target)
{
	
}