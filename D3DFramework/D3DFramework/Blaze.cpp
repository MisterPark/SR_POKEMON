#include "stdafx.h"
#include "Blaze.h"
#include "Effect.h"

Blaze::Blaze()
{
}

Blaze::Blaze(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float _lifeTime, float att)
{
	transform->position = pos;
	transform->scale = size;
	direction = dir;
	lifeTime = _lifeTime;
	attack = att;
	moveSpeed = speed;

	startKey = start;
	endKey = end;

	isOnTerrain = true;

	offsetY = 0.3f;

	anim->SetSprite(start, end);
	anim->SetDelay(0.2f);
	anim->SetLoop(false);
}

Blaze::~Blaze()
{
}

void Blaze::Initialize()
{
}

void Blaze::Update()
{
	Bullet::Update();

	if (anim->GetCurrentSprite() == endKey) isDead = true;
}

void Blaze::Release()
{
}

void Blaze::OnCollision(GameObject * target)
{
	AddToCollideList(target);

	Vector3 pos = transform->position;

	Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_EXPLOSION_01, TextureKey::FIRE_EXPLOSION_08, 0.03f);
	ObjectManager::AddObject(fx);
}

Blaze * Blaze::Create(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float lifeTime, float att)
{
	Blaze* instance = new Blaze(pos, size, start, end, dir, speed, lifeTime, att);
	return instance;
}