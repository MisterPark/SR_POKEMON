#include "stdafx.h"
#include "Decoration.h"
#include "Environment.h"
#include "Terrain.h"
#include "Rectangle.h"

Decoration::Decoration()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	mesh->SetBlendMode(BlendMode::ALPHA_TEST);
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");
}

Decoration::~Decoration()
{
}

void Decoration::Update()
{
	GameObject::Update();
	OnTerrain();
}

void Decoration::Render()
{
	GameObject::Render();
}

void Decoration::OnTerrain()
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

	if (isOnTerrain)
	{
		if (onTerrain)
			transform->position.y = y + offsetY;
		else
		{
			transform->position.y = offsetY;
		}
	}
	else
	{
		if (transform->position.y < y) Die();
	}
}
