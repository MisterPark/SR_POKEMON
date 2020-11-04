#include "stdafx.h"
#include "TriggerBox.h"
#include "Terrain.h"
#include "Environment.h"
#include "Plane.h"
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
	attack = 0.f;
	offsetY = 0.01f;
	team = Team::MONSTERTEAM;
	CollisionManager::RegisterObject(COLTYPE::TRIGGERBOX, this);
	Mesh* mesh = (Mesh*)AddComponent<PKH::Plane>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
	mesh->SetTexture(TextureKey::MONSTERBALL);

}

void TriggerBox::Release()
{
}

void TriggerBox::Update()
{
	GameObject::Update();
	OnTerrain();
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
