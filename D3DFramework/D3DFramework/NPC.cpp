#include "stdafx.h"
#include "NPC.h"
#include "Environment.h"
#include "Terrain.h"

NPC::NPC()
{
	Initialize();
}

NPC::~NPC()
{
	Release();
}

void NPC::Initialize()
{
	
}

void NPC::Release()
{
	
}

void NPC::Update()
{
}

void NPC::Render()
{
}

void NPC::OnCollision(GameObject* target)
{
}

void NPC::OnTerrain()
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
