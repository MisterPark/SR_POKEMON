#include "stdafx.h"
#include "Bullet_FireBlast.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_FireBlast::Bullet_FireBlast()
{
	anim->SetSprite(TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 4.f;
	stat.moveSpeed = 8.f;

}

Bullet_FireBlast::~Bullet_FireBlast()
{
}

void Bullet_FireBlast::Update()
{
	Bullet::Update();
	//stat.attack = TimeManager::DeltaTime() * initAttack;

		anim->SetSprite(TextureKey::BULLET_FIRE4_01, TextureKey::BULLET_FIRE4_13);
		//stat.moveSpeed = 8.f;
	

}

void Bullet_FireBlast::Render()
{
	Bullet::Render();
}

void Bullet_FireBlast::OnCollision(GameObject* target)
{
}