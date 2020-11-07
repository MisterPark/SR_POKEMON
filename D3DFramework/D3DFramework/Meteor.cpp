#include "stdafx.h"
#include "Meteor.h"
#include "Effect.h"

Meteor::Meteor()
{
}

Meteor::Meteor(const Vector3 & pos, const Vector3 & size, const Vector3 & dir, float speed, float _lifeTime, float att)
{
	transform->position = pos;
	transform->scale = size;
	direction = dir;
	lifeTime = _lifeTime;
	stat.attack = att * 2.f;
	stat.moveSpeed = speed;

	offsetY = 0.3f;

	startKey = TextureKey::METEOR_01;
	endKey = TextureKey::METEOR_01;

	anim->SetSprite(startKey, endKey);
	anim->SetDelay(0.f);
	anim->SetLoop(false);
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

	if (anim->IsEndFrame()) isDead = true;
}

void Meteor::Release()
{
}

void Meteor::OnCollision(GameObject * target)
{
	
}

void Meteor::CollideOnTerrain()
{
	Vector3 pos = transform->position;

	Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::METEOR_01, TextureKey::METEOR_11, 0.05f);
	ObjectManager::AddObject(fx);
}

Meteor * Meteor::Create(const Vector3 & pos, const Vector3 & size, float att, const Vector3 & dir, float speed, float lifeTime)
{
	Meteor* instance = new Meteor(pos, size, dir, speed, lifeTime, att);
	return instance;
}