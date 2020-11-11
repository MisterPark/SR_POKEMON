#include "stdafx.h"
#include "Bullet_WaterFlow.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_WaterFlow::Bullet_WaterFlow()
{
	anim->SetSprite(TextureKey::BULLET_WATER3_01, TextureKey::BULLET_WATER3_09);
	anim->SetLoop(true);
	anim->SetDelay(0.1f);

	transform->scale = { 0.25f, 0.25f, 0.25f };

	lifeTime = 2.6f;
	stat.moveSpeed = 5.f;
	isOnTerrain = true;
	isBillboard = true;
	
	//transform->eulerAngles.y = D3DXToRadian(0.f) + Player::GetInstance()->GetRadianY();
	//transform->eulerAngles.x = D3DXToRadian(80.f);
	offsetY = 0.25f;
}

Bullet_WaterFlow::~Bullet_WaterFlow()
{
}

void Bullet_WaterFlow::Update()
{
	Bullet::Update();
	SoundManager::PlayOverlapSound(L"WaterFlow.wav", SoundChannel::EFFECT, 0.3);
	SoundManager::SetVolume(SoundChannel::EFFECT, 0.08f);

	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_27, TextureKey::BULLET_ICE1_33, 0.05f);
		ObjectManager::AddObject(fx);
		SoundManager::PlayOverlapSound(L"WaterCollide.wav", SoundChannel::EFFECT);
		SoundManager::SetVolume(SoundChannel::EFFECT, 0.05f);
	}
}

void Bullet_WaterFlow::Render()
{
	Bullet::Render();
}

void Bullet_WaterFlow::OnCollision(GameObject* target)
{
	isDead = true;
	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_ICE1_27, TextureKey::BULLET_ICE1_33, 0.05f);
	ObjectManager::AddObject(fx);
}