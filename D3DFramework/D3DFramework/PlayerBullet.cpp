#include "stdafx.h"
#include "PlayerBullet.h"
#include "Rectangle.h"

PlayerBullet::PlayerBullet()
{
    SetTexture(State::IDLE, TextureKey::BULLET_TEARS_01, 1);
	UpdateAnimation();
    state = State::IDLE;
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

    transform->scale.x *= 0.5f;
    transform->scale.y *= 0.5f;
    transform->scale.z *= 0.5f;

	moveSpeed = 3.f;
}

PlayerBullet::PlayerBullet(const Vector3 & pos, const Vector3 & scale, const Vector3 & dir, const int & type, const bool & isPlayer)
	: Bullet(pos, scale, dir, isPlayer)
{
	transform->position = pos;
	transform->scale = scale;
	direction = dir;

	Init();
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Init()
{
	switch (bulletType)
	{
	case 0:
		SetTexture(State::IDLE, TextureKey::BULLET_TEARS_01, 1);
		SetTexture(State::ATTACK, TextureKey::BULLET_TEARS_01, 1);
		break;
	case 1: break;
	case 2: break;
	}

	UpdateAnimation();

	state = State::IDLE;

	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	moveSpeed = 5.f;
}

void PlayerBullet::Update()
{
	Bullet::Update();
}

void PlayerBullet::Render()
{
	Bullet::Render();
}

void PlayerBullet::OnCollision(GameObject* target)
{
    if (target->isAlliance == this->isAlliance) {
        return;
    }

    isDead = true;
}