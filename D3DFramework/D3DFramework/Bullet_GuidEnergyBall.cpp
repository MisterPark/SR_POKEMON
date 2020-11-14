#include "stdafx.h"
#include "Bullet_GuidEnergyBall.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"
#include "Effect.h"

Bullet_GuidEnergyBall::Bullet_GuidEnergyBall()
{
	anim->SetSprite(TextureKey::BULLET_ENERGY1_01, TextureKey::BULLET_ENERGY1_13);
	anim->SetLoop(true);
	anim->SetDelay(0.05f);

	transform->scale = { 0.f, 0.f, 0.f };

	lifeTime = 12.f;
	//stat.moveSpeed = 3.f;
}

Bullet_GuidEnergyBall::~Bullet_GuidEnergyBall()
{
}

void Bullet_GuidEnergyBall::Update()
{
	if (lifeTime > 11.f) {
		transform->scale.x += TimeManager::DeltaTime() * 0.7f;
		transform->scale.y += TimeManager::DeltaTime() * 0.7f;
		transform->scale.z += TimeManager::DeltaTime() * 0.7f;
		stat.moveSpeed = 0.f;
	}
	else if (lifeTime < 1.f) {
		transform->scale.x -= TimeManager::DeltaTime() * 0.7f;
		transform->scale.y -= TimeManager::DeltaTime() * 0.7f;
		transform->scale.z -= TimeManager::DeltaTime() * 0.7f;
	}
	else {
		if (!guid) {
			stat.moveSpeed = 0.1f;
			Character* player = Player::GetInstance()->GetCharacter();
			guidPos.x = player->transform->position.x;
			guidPos.z = player->transform->position.z;
			direction.x = guidPos.x - transform->position.x;
			direction.z = guidPos.z - transform->position.z;
			Vector3::Normalize(&direction);
			guid = true;
		}
		else {
			if (!guidAccelDec) {
				float distX = guidPos.x - transform->position.x;
				float distZ = guidPos.z - transform->position.z;
				
				float dis = sqrt(distX * distX + distZ * distZ);

				if (dis > 0.4f) {
					if (stat.moveSpeed < 6.5f)
						stat.moveSpeed *= 1.1f;
					transform->position.x += direction.x * stat.moveSpeed * TimeManager::DeltaTime();
					transform->position.z += direction.z * stat.moveSpeed * TimeManager::DeltaTime();
				}
				else {
					guidAccelDecTime = 0.1f;
					guidAccelDec = true;
					//stat.moveSpeed = 0.f;
				}
			}
			else {
				if (guidAccelDecTime > 0.f) {
					guidAccelDecTime -= TimeManager::DeltaTime();
					if (stat.moveSpeed < 6.5f)
						stat.moveSpeed *= 1.1f;
					transform->position.x += direction.x * stat.moveSpeed * TimeManager::DeltaTime();
					transform->position.z += direction.z * stat.moveSpeed * TimeManager::DeltaTime();
				}
				else if (stat.moveSpeed > 0.f) {
					stat.moveSpeed -= 6.5f * TimeManager::DeltaTime();
					transform->position.x += direction.x * stat.moveSpeed * TimeManager::DeltaTime();
					transform->position.z += direction.z * stat.moveSpeed * TimeManager::DeltaTime();
				}
				else {
					guidAccelDec = false;
					guid = false;
				}
			}
		}
	}

	Bullet::Update();
	if (IsDead()) {
		Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_WEB1_02, TextureKey::BULLET_WEB1_03, 0.05f);
		ObjectManager::AddObject(fx);
	}
}

void Bullet_GuidEnergyBall::Render()
{
	Bullet::Render();
}

void Bullet_GuidEnergyBall::OnCollision(GameObject* target)
{
	Die();
	Effect* fx = Effect::Create(transform->position, transform->scale, TextureKey::BULLET_WEB1_02, TextureKey::BULLET_WEB1_03, 0.05f);
	ObjectManager::AddObject(fx);
}