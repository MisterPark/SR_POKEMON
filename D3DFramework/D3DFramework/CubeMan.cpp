#include "stdafx.h"
#include "CubeMan.h"
#include "Cube.h"
#include "Terrain.h"

PKH::CubeMan::CubeMan()
{
	//transform->scale = { 0.5f,0.5f, 0.5f };
	AddComponent<Cube>(L"Mesh");
}

PKH::CubeMan::~CubeMan()
{
}

void PKH::CubeMan::Update()
{
	if (InputManager::GetKey(VK_UP))
	{
		transform->position.z += 10.f *TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		transform->position.z -= 10.f * TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_LEFT))
	{
		transform->position.x -= 10.f * TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_RIGHT))
	{
		transform->position.x += 10.f * TimeManager::DeltaTime();
	}

	GameObject* obj = ObjectManager::GetInstance()->FindObject<Player>();
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");

	float y;
	bool onTerrain = mesh->GetYFromPoint(&y, transform->position.x, transform->position.z);
	if( onTerrain)
		transform->position.y = y;
	else
	{
		transform->position.y = 0;
	}

	GameObject::Update();
}

void PKH::CubeMan::Initialize()
{
}

void PKH::CubeMan::Release()
{
}
