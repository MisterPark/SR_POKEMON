#include "stdafx.h"
#include "XClaw.h"
#include "Effect.h"

XClaw::XClaw()
{
}

XClaw::XClaw(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, const Vector3 & dir, float speed, float _lifeTime, float att)
{
	transform->position = pos;
	transform->scale = size;
	direction = dir;
	lifeTime = _lifeTime;
	stat.attack = att * 2.f;
	stat.moveSpeed = speed;

	startKey = start;
	endKey = end;

	animDelay = (float)lifeTime / (float(end) - float(start));

	isOnTerrain = true;

	offsetY = 0.3f;

	anim->SetSprite(start, end);
	anim->SetDelay(animDelay);
	anim->SetLoop(false);
}

XClaw::~XClaw()
{
}

void XClaw::Initialize()
{
}

void XClaw::Update()
{
	Bullet::Update();

	if (anim->IsEndFrame()) isDead = true;
}

void XClaw::Release()
{
}

void XClaw::OnCollision(GameObject * target)
{
	AddToCollideList(target);
	Vector3 pos = transform->position;

	Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_EXPLOSION_01, TextureKey::FIRE_EXPLOSION_08, 0.03f);
	ObjectManager::AddObject(fx);
}

XClaw * XClaw::Create(const Vector3 & pos, const Vector3 & size, TextureKey start, TextureKey end, float att, const Vector3 & dir, float speed, float lifeTime)
{
	XClaw* instance = new XClaw(pos, size, start, end, dir, speed, lifeTime, att);
	return instance;
}