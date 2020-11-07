#include "stdafx.h"
#include "Bullet_FireWallWave.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_FireWallWave::Bullet_FireWallWave()
{
	anim->SetSprite(TextureKey::BULLET_FIRE4_03, TextureKey::BULLET_FIRE4_10);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);


	stat.attack = initAttack;
	lifeTime = 20.f;
	stat.moveSpeed = 3.f;
	isBillboard = false;
	isOnTerrain = true;

}

Bullet_FireWallWave::~Bullet_FireWallWave()
{

}

void Bullet_FireWallWave::Update()
{
	if (transform->position.z < 1)
		Die();
	Bullet::Update();
	stat.attack = TimeManager::DeltaTime() * initAttack;
	

}

void Bullet_FireWallWave::Render()
{
	Bullet::Render();
}

void Bullet_FireWallWave::OnCollision(GameObject* target)
{

		/*Die();*/
	
}