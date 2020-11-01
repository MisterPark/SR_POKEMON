#include "stdafx.h"
#include "PlayerBullet.h"
#include "Rectangle.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::PlayerBullet(const Vector3& pos, const Vector3& dir, const Type& type, const bool& isAlliance) :
	Bullet(pos, { 1.f, 1.f, 1.f }, dir, isAlliance),
	bulletType(type)
{
	transform->position = pos;
	transform->scale = { 1.f, 1.f, 1.f };
	direction = dir;

	moveSpeed = 10.f;
	lifeTime = 1.2f;
	isCollision = false;

	att = 1.f;

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

		SetTexture(State::IDLE, TextureKey::BULLET_LEAF_09, 1);
		transform->eulerAngles.x = D3DXToRadian(90.f);
		transform->eulerAngles.y = D3DXToRadian(135.f) + Player::GetInstance()->GetRadianY();
		break;

	case FIRE:
		transform->scale = { 0.2f, 0.2f, 0.2f };
		SetTexture(State::IDLE, TextureKey::BULLET_FIRE_01, 5);
		SetTexture(State::HURT, TextureKey::FIRE_EXPLOSION_01, 8);
		break;

	case WATER:
		transform->scale = { 0.1f, 0.1f, 0.1f };
		SetTexture(State::IDLE, TextureKey::BULLET_WATER_01, 2);
		break;
	}

	UpdateAnimation();

	state = State::IDLE;

	anim->SetLoop(true);
	anim->SetDelay(0.05f);
}

void PlayerBullet::Update()
{
	if (true == isDead) return;
	if (IsEndColl()) isDead = true;

	Bullet::Update();

	CalcLifeTime();
}

void PlayerBullet::Render()
{
	Bullet::Render();
}

void PlayerBullet::OnCollision(GameObject* target)
{
	if (isCollision) return;
    if (target->isAlliance == this->isAlliance) {
        return;
    }

	CollSetByType();
}

void PlayerBullet::CollSetByType()
{
	isCollision = true;
	att = 0;
	state = State::HURT;
	moveSpeed = 0.f;

	switch (bulletType)
	{
	case PlayerBullet::LEAF:
		break;
	case PlayerBullet::FIRE:
		transform->scale = { 0.5f, 0.5f, 0.5f };
		anim->SetDelay(0.03f);
		anim->SetLoop(false);
		break;
	case PlayerBullet::WATER:
		break;
	}
	//UpdateAnimation();
}

bool PlayerBullet::IsEndColl()
{
	bool ret = false;

	if (isCollision)
	{
		switch (bulletType)
		{
		case PlayerBullet::LEAF:
			break;
		case PlayerBullet::FIRE:
			if (anim->GetCurrentSprite() == TextureKey::FIRE_EXPLOSION_08) ret = true;
			break;
		case PlayerBullet::WATER:
			break;
		}
	}

	return ret;
}

void PlayerBullet::CalcLifeTime()
{
	lifeTime -= TimeManager::DeltaTime();

	if (lifeTime <= 0.f) isDead = true;
}
