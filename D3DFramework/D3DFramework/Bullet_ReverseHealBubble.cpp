#include "stdafx.h"
#include "Bullet_ReverseHealBubble.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_ReverseHealBubble::Bullet_ReverseHealBubble()
{
	anim->SetSprite(TextureKey::BULLET_WATERDROP1_01, TextureKey::BULLET_WATERDROP1_01);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.6f, 0.6f, 0.6f };

	stat.attack = initAttack;
	lifeTime = 3.6f;
	stat.moveSpeed = 3.f;

}

Bullet_ReverseHealBubble::~Bullet_ReverseHealBubble()
{
}

void Bullet_ReverseHealBubble::Update()
{
	Bullet::Update();
	transform->position.y -= stat.moveSpeed * TimeManager::DeltaTime();
	if (lifeTime > 3.f) {
		stat.moveSpeed = 0.f;
	}
	else {
		anim->SetSprite(TextureKey::BULLET_WATERDROP1_02, TextureKey::BULLET_WATERDROP1_02);
		stat.moveSpeed = 8.f;
	}

	//if (isDead) {
	//	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_HEART1_01, TextureKey::BULLET_HEART1_05, 0.2f);
	//	fx->transform->position.y += 1.f;
	//	ObjectManager::AddObject(fx);
	//}
}

void Bullet_ReverseHealBubble::Render()
{
	Bullet::Render();
}

void Bullet_ReverseHealBubble::OnCollision(GameObject* target)
{
	isDead = true;
}