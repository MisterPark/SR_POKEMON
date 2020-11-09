#include "stdafx.h"
#include "Bullet_Tsunami.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_Tsunami::Bullet_Tsunami()
{
	anim->SetSprite(TextureKey::BULLET_WATER1_01, TextureKey::BULLET_WATER1_04);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.4f, 0.4f, 0.4f };

	lifeTime = 3.6f;
	stat.moveSpeed = 6.5f;
	isOnTerrain = true;
	isBillboard = false;
	//transform->eulerAngles.x = D3DXToRadian(90.f);
	//transform->eulerAngles.x = D3DXToRadian(180.f);
	transform->eulerAngles.y = D3DXToRadian(0.f) + Player::GetInstance()->GetRadianY();
	transform->eulerAngles.x = D3DXToRadian(angleX);
	offsetY = 0.1f;
}

Bullet_Tsunami::~Bullet_Tsunami()
{
}

void Bullet_Tsunami::Update()
{
	if (angleXAdd) {
		angleX += 2.f;
		if (angleX > 80.f) {
			angleXAdd = false;
		}
	}
	else {
		angleX -= 2.f;
		if (angleX < 10.f) {
			angleXAdd = true;
		}
	}

	transform->eulerAngles.y = D3DXToRadian(0.f) + Player::GetInstance()->GetRadianY();
	transform->eulerAngles.x = D3DXToRadian(angleX);

	Bullet::Update();
	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_27, TextureKey::BULLET_ICE1_33, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_Tsunami::Render()
{
	Bullet::Render();
}

void Bullet_Tsunami::OnCollision(GameObject* target)
{
	isDead = true;
	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_27, TextureKey::BULLET_ICE1_33, 0.05f);
	ObjectManager::AddObject(fx);
}