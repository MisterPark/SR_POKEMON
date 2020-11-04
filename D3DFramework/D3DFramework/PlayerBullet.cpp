#include "stdafx.h"
#include "PlayerBullet.h"
#include "Effect.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::PlayerBullet(const Vector3& pos, const Vector3& dir, const Type& type, const float& att) :
	bulletType(type)
{
	transform->position = pos;
	direction = dir;

	attack = att;
	moveSpeed = 10.f;
	lifeTime = 1.2f;

	animDelay = 0.05f;

	InitByType();
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::InitByType()
{
	switch (bulletType)
	{
	case LEAF:
		isBillboard = false;

		transform->scale = { 0.15f, 0.15f, 0.15f };

		anim->SetSprite(TextureKey::BULLET_LEAF_09, TextureKey::BULLET_LEAF_09);

		transform->eulerAngles.x = D3DXToRadian(90.f);
		transform->eulerAngles.y = D3DXToRadian(135.f) + Player::GetInstance()->GetRadianY();
		break;

	case FIRE:
		transform->scale = { 0.2f, 0.2f, 0.2f };
		anim->SetSprite(TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_06);
		break;

	case WATER:
		transform->scale = { 0.1f, 0.1f, 0.1f };
		anim->SetSprite(TextureKey::BULLET_WATER_01, TextureKey::BULLET_WATER_02);
		break;
	}

	anim->SetLoop(isLoop);
	anim->SetDelay(animDelay);
}

void PlayerBullet::Update()
{
	if (true == isDead) return;

	Bullet::Update();

	CalcLifeTime();
}

void PlayerBullet::Render()
{
	Bullet::Render();
}

void PlayerBullet::OnCollision(GameObject* target)
{
	CollSetByType();
}

void PlayerBullet::CollSetByType()
{
	isDead = true;
	Vector3 pos = transform->position;

	switch (bulletType)
	{
	case PlayerBullet::LEAF:
		break;
	case PlayerBullet::FIRE:
	{
		Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_EXPLOSION_01, TextureKey::FIRE_EXPLOSION_08, 0.03f);
		ObjectManager::AddObject(fx);
		break;
	}
	case PlayerBullet::WATER:
		break;
	}
}

void PlayerBullet::CalcLifeTime()
{
	lifeTime -= TimeManager::DeltaTime();

	if (lifeTime <= 0.f) isDead = true;
}
