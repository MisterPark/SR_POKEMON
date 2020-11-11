#include "stdafx.h"
#include "Bullet_WaterBomb.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_WaterBomb::Bullet_WaterBomb()
{
	anim->SetSprite(TextureKey::BULLET_WATER2_01, TextureKey::BULLET_WATER2_03);
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	transform->scale = { 0.5f, 0.5f, 0.5f };

	lifeTime = 2.f;
	stat.moveSpeed = 5.f;
	gravityAccel = -0.04f;
	createDelay = 0.1f;
	isOnTerrain = false;
	
}

Bullet_WaterBomb::~Bullet_WaterBomb()
{
}

void Bullet_WaterBomb::Update()
{
	Bullet::Update();

	if (createDelay > 0.f) {
		createDelay -= TimeManager::DeltaTime();
		stat.attack = 0.f;
	}

	transform->position.y -= gravityAccel;
	gravityAccel += 0.1f * TimeManager::DeltaTime();

	if (isDead) {
		Effect* fx = Effect::Create(transform->position, transform->scale * 2.f, TextureKey::BULLET_ICE1_26, TextureKey::BULLET_ICE1_33, 0.05f);
		ObjectManager::AddObject(fx);
		SoundManager::PlayOverlapSound(L"WaterBomb3.wav", SoundChannel::PLAYER_EFFECT);
		SoundManager::SetVolume(SoundChannel::PLAYER_EFFECT, 0.1f);
	}


}

void Bullet_WaterBomb::Render()
{
	Bullet::Render();
}

void Bullet_WaterBomb::OnCollision(GameObject* target)
{
	//isDead = true;

	if (createDelay < 0.f) {
		stat.attack = initAttack;
		gravityAccel = -0.04f;
		createDelay = 0.8f;
		direction.x *= 0.7f;
		direction.z *= 0.7f;
		lifeTime = 1.2f;
		SoundManager::PlayOverlapSound(L"WaterBomb2.mp3", SoundChannel::PLAYER_EFFECT);
		SoundManager::SetVolume(SoundChannel::PLAYER_EFFECT, 0.1f);
	}

}