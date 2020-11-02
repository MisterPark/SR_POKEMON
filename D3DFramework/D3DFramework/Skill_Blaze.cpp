#include "stdafx.h"
#include "Skill_Blaze.h"
#include "Blaze.h"
#include "Effect.h"

Skill_Blaze::Skill_Blaze()
{
	coolTime = 0.6f;
}

Skill_Blaze::~Skill_Blaze()
{
}

void Skill_Blaze::Active(const Character* character)
{
	Vector3 pos = character->transform->position;
	Vector3 look = { 0.f, 0.f, 1.f };

	Vector3 dir = character->direction;
	float radianY = character->transform->eulerAngles.y;

	Matrix rot;
	D3DXMatrixRotationY(&rot, radianY);
	D3DXVec3TransformNormal(&look, &look, &rot);

	Vector3 position = pos + (look * 0.2f);

	position.y += 0.1f;

	float size = 0.3f;

	// 스킬 사용 시 생성할 이펙트와 충돌체 등등
	Effect* fx = Effect::Create(pos, { 0.2f, 0.2f, 0.2f }, TextureKey::FIRE_ROUND_01, TextureKey::FIRE_ROUND_05, 0.1f, true);
	ObjectManager::AddObject(fx);

	Vector3 pos2 = position + look;

	Blaze* instance = Blaze::Create(position, { 0.4f, 0.4f, 0.4f }, TextureKey::FIELD_FIRE_01, TextureKey::FIELD_FIRE_07, look, 30.f, 2.f, 3.f);
	ObjectManager::AddObject(instance);

	if (character->GetIsEnemy())
		CollisionManager::RegisterObject(COLTYPE::ENEMY_ATTACK, instance);
	else
		CollisionManager::RegisterObject(COLTYPE::PLAYER_ATTACK, instance);
}

Skill * Skill_Blaze::Create()
{
	Skill* instance = new Skill_Blaze;

	return instance;
}