#include "stdafx.h"
#include "XClaw.h"
#include "Effect.h"

XClaw::XClaw()
{
}

XClaw::XClaw(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float speed, float _lifeTime, float att)
{
	transform->position = pos;
	transform->scale = size;
	direction = dir;
	lifeTime = _lifeTime;
	stat.attack = att * 2.f;
	stat.moveSpeed = speed;

	isOnTerrain = true;

	offsetY = 0.3f;

	startKey = TextureKey::X_CLAW_01;
	endKey = TextureKey::X_CLAW_08;

	anim->SetSprite(startKey, endKey);
	anim->SetDelay(lifeTime / 8.f);
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

XClaw * XClaw::Create(const Vector3 & pos, const Vector3 & size, float att, const Vector3 & dir, float speed, float lifeTime)
{
	XClaw* instance = new XClaw(pos, size, dir, speed, lifeTime, att);
	return instance;
}