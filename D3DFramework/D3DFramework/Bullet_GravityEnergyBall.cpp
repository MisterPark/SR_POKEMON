#include "stdafx.h"
#include "Bullet_GravityEnergyBall.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_GravityEnergyBall::Bullet_GravityEnergyBall()
{
	anim->SetSprite(TextureKey::BULLET_ENERGY2_01, TextureKey::BULLET_ENERGY2_32);
	anim->SetLoop(true);
	anim->SetDelay(0.05f);

	transform->scale = { 0.f, 0.f, 0.f };

	lifeTime = 15.f;
	stat.moveSpeed = 0.f;
	stat.attack = 0.f;
}

Bullet_GravityEnergyBall::~Bullet_GravityEnergyBall()
{
}

void Bullet_GravityEnergyBall::Update()
{
	Bullet::Update();
	if (lifeTime > 14.f) {
		transform->scale.x += 4.f * TimeManager::DeltaTime();
		transform->scale.y += 4.f * TimeManager::DeltaTime();
		transform->scale.z += 4.f * TimeManager::DeltaTime();
	}
	else if (lifeTime < 1.f) {
		transform->scale.x -= 4.f * TimeManager::DeltaTime();
		transform->scale.y -= 4.f * TimeManager::DeltaTime();
		transform->scale.z -= 4.f * TimeManager::DeltaTime();
	}
	//stat.attack = initAttack * 0.4f * TimeManager::DeltaTime();

	if (IsDead()) {
		
	}
}

void Bullet_GravityEnergyBall::Render()
{
	Bullet::Render();
}

void Bullet_GravityEnergyBall::OnCollision(GameObject* target)
{
	//Die();
	
	Character* player = Player::GetInstance()->GetCharacter();
	Vector3 gravityDir;
	gravityDir.x = transform->position.x - player->transform->position.x;
	gravityDir.y = 0.f;
	gravityDir.z = transform->position.z - player->transform->position.z;

	Vector3::Normalize(&gravityDir);

	player->transform->position.x += gravityDir.x * TimeManager::DeltaTime();
	player->transform->position.z += gravityDir.z * TimeManager::DeltaTime();
}