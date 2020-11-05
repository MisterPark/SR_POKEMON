#include "stdafx.h"
#include "TriggerBox.h"
#include "Terrain.h"
#include "Environment.h"
#include "Plane.h"
#include "Rectangle.h"
TriggerBox::TriggerBox()
{
	Initialize();
	
	/*AddComponent<Cube>(L"Mesh");*/
}


TriggerBox::~TriggerBox()
{
	CollisionManager::GetInstance()->DisregisterObject(this);
}

void TriggerBox::Initialize()
{
	stat.attack = 0.f;
	offsetY = 1.f;
	team = Team::MONSTERTEAM;
	CollisionManager::RegisterObject(COLTYPE::TRIGGERBOX, this);
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
	/*mesh->SetTexture(TextureKey::MONSTERBALL);*/

	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
	anim->SetSprite(TextureKey::MONSTERBALL, TextureKey::MONSTERBALL);
	anim->SetLoop(false);

}

void TriggerBox::Release()
{
}

void TriggerBox::Update()
{
	GameObject::Update();
	OnTerrain();
	Billboard();
}

void TriggerBox::OnCollision(GameObject * target)
{
	if (this->team == target->team) return;

	if (OnTriggered != nullptr)
		OnTriggered();

	isDead = true;
}

void TriggerBox::OnTerrain()
{
	GameObject* obj = ObjectManager::GetInstance()->FindObject<Environment>();
	if (obj == nullptr)
	{
		transform->position.y = offsetY;
		return;
	}
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");
	if (mesh == nullptr)
	{
		transform->position.y = offsetY;
		return;
	}

	float y;
	bool onTerrain = mesh->GetYFromPoint(&y, transform->position.x, transform->position.z);
	if (onTerrain)
		transform->position.y = y + offsetY;
	else
	{
		transform->position.y = offsetY;
	}
}

void TriggerBox::Portal()
{
	anim->SetSprite(TextureKey::BULLET_WATER2_01, TextureKey::BULLET_WATER2_03);
	anim->SetDelay(0.1f);
	anim->SetLoop(true);
}
