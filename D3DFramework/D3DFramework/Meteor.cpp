#include "stdafx.h"
#include "Meteor.h"
#include "Effect.h"

Meteor::Meteor()
{
}

Meteor::Meteor(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float att, float speed)
{
	transform->position = pos;
	transform->scale = size;
	initSize = size.x;
	stackSize = 0.f;
	direction = dir;

	lifeTime = 9999.f;
	initAttack = att;
	stat.attack = att;
	stat.moveSpeed = speed;

	offsetY = 0.3f;

	startKey = TextureKey::METEOR_01;
	endKey = TextureKey::METEOR_01;

	anim->SetSprite(startKey, endKey);
	anim->SetDelay(1.f);
	anim->SetLoop(true);

	isExplosion = false;
}

Meteor::~Meteor()
{
}

void Meteor::Initialize()
{
}

void Meteor::Update()
{
	Bullet::Update();

	if (isExplosion)
	{
		stat.attack = TimeManager::DeltaTime() * initAttack * 0.7f;

		stackSize += TimeManager::DeltaTime() * 5.f;
		float bigSize = initSize + stackSize;

		transform->scale = { bigSize, bigSize, bigSize };

		transform->position.y += TimeManager::DeltaTime() * 4.f;

		Camera::GetInstance()->Shake(0.1f, 0.2f);

		if (endKey == anim->GetCurrentSprite())
			Die();
	}
}

void Meteor::Release()
{
}

void Meteor::OnCollision(GameObject * target)
{
	if (!isExplosion) AddToCollideList(target);

	if (isExplosion)
	{
		Vector3 pos = transform->position;

		Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_EXPLOSION_01, TextureKey::FIRE_EXPLOSION_08, 0.1f);
		ObjectManager::AddObject(fx);
	}
}

void Meteor::CollideOnTerrain()
{
	if (isCollideOnTerrain)
	{
		if (!isExplosion)
		{
			collideList.clear();

			stat.moveSpeed = 0.f;

			startKey = TextureKey::METEOR_01;
			endKey = TextureKey::METEOR_11;

			anim->SetSprite(startKey, endKey);
			anim->SetDelay(0.1f);
			anim->SetLoop(false);

			stat.attack = TimeManager::DeltaTime() * initAttack;

			isExplosion = true;
		}
	}
}

Meteor * Meteor::Create(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float att, float speed)
{
	Meteor* instance = new Meteor(pos, size, dir, att, speed);
	return instance;
}