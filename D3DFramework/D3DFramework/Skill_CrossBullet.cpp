#include "stdafx.h"
#include "Skill_CrossBullet.h"
#include "PlayerBullet.h"
#include "Effect.h"

Skill_CrossBullet::Skill_CrossBullet()
{
}

Skill_CrossBullet::~Skill_CrossBullet()
{
}

void Skill_CrossBullet::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 dir = character->direction;

	PlayerBullet* bullet = new PlayerBullet(pos, dir, PlayerBullet::WATER);
	ObjectManager::AddObject(bullet);

	Effect* effect = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::BULLET_FIRE_01, TextureKey::BULLET_FIRE_05, 0.2f, true);
	ObjectManager::AddObject(effect);
}

Skill * Skill_CrossBullet::Create()
{
	Skill* instance = new Skill_CrossBullet;

	return instance;
}