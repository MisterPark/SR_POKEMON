#include "stdafx.h"
#include "Character.h"
#include "Terrain.h"
#include "Environment.h"

Character::Character()
{
	CollisionManager::RegisterObject(this);
}

Character::~Character()
{
	CollisionManager::DisregisterObject(this);
}

void Character::Update()
{
	GameObject::Update();
}

void Character::Render()
{
	GameObject::Render();
}

void Character::Initialize()
{
}

void Character::Release()
{
}

void Character::OnTerrain()
{
	GameObject* obj = ObjectManager::GetInstance()->FindObject<Environment>();
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");

	float y;
	bool onTerrain = mesh->GetYFromPoint(&y, transform->position.x, transform->position.z);
	if (onTerrain)
		transform->position.y = y + offsetY;
	else
	{
		transform->position.y = offsetY;
	}
}
