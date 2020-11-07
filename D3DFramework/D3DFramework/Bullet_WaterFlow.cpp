#include "stdafx.h"
#include "Bullet_WaterFlow.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_WaterFlow::Bullet_WaterFlow()
{
	anim->SetSprite(TextureKey::BULLET_WATER1_01, TextureKey::BULLET_WATER1_04);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 2.6f;
	stat.moveSpeed = 5.f;
	isOnTerrain = true;
	isBillboard = false;
	//transform->eulerAngles.x = D3DXToRadian(90.f);
	//transform->eulerAngles.x = D3DXToRadian(180.f);
	transform->eulerAngles.y = D3DXToRadian(0.f) + Player::GetInstance()->GetRadianY();
	transform->eulerAngles.x = D3DXToRadian(80.f);
	offsetY = 0.1f;
}

Bullet_WaterFlow::~Bullet_WaterFlow()
{
}

void Bullet_WaterFlow::Update()
{
	Bullet::Update();
	//if (isDead) {
	//	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_TEARS_01, TextureKey::BULLET_WEB1_03, 0.05f);
	//	ObjectManager::AddObject(fx);
	//}
}

void Bullet_WaterFlow::Render()
{
	Bullet::Render();
}

void Bullet_WaterFlow::OnCollision(GameObject* target)
{
	isDead = true;
	//Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_WEB1_02, TextureKey::BULLET_WEB1_03, 0.05f);
	//ObjectManager::AddObject(fx);
}