#include "stdafx.h"
#include "Bullet_ShortWaterFlow.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_ShortWaterFlow::Bullet_ShortWaterFlow()
{
	anim->SetSprite(TextureKey::BULLET_WATER1_01, TextureKey::BULLET_WATER1_01);
	anim->SetLoop(false);
	anim->SetDelay(0.1f);

	transform->scale = { 0.3f, 0.3f, 0.3f };

	lifeTime = 0.5f;
	stat.moveSpeed = 5.f;
	isOnTerrain = true;
	isBillboard = false;
	//transform->eulerAngles.x = D3DXToRadian(90.f);
	//transform->eulerAngles.x = D3DXToRadian(180.f);
	transform->eulerAngles.y = D3DXToRadian(0.f) + Player::GetInstance()->GetRadianY();
	transform->eulerAngles.x = D3DXToRadian(80.f);
	offsetY = 0.1f;
}

Bullet_ShortWaterFlow::~Bullet_ShortWaterFlow()
{
}

void Bullet_ShortWaterFlow::Update()
{
	Bullet::Update();
	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_27, TextureKey::BULLET_ICE1_33, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_ShortWaterFlow::Render()
{
	Bullet::Render();
}

void Bullet_ShortWaterFlow::OnCollision(GameObject* target)
{
	isDead = true;
	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_27, TextureKey::BULLET_ICE1_33, 0.05f);
	ObjectManager::AddObject(fx);
}