#include "stdafx.h"
#include "Bullet_Quake.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Quake::Bullet_Quake()
{
	anim->SetSprite(TextureKey::BULLET_INVISIBLE_01, TextureKey::BULLET_INVISIBLE_01);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);
	isOnTerrain = true;
	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 1.5f;
	stat.moveSpeed = 0.f;

}

Bullet_Quake::~Bullet_Quake()
{
}

void Bullet_Quake::Update()
{
	Bullet::Update();
	stat.attack = TimeManager::DeltaTime() * initAttack;
	lifeTime -= TimeManager::DeltaTime();

}

void Bullet_Quake::Render()
{
	Bullet::Render();
}

void Bullet_Quake::OnCollision(GameObject* target)
{
	
	if (lifeTime < 0)
	{
		Die();
	}
}