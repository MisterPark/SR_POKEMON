#include "stdafx.h"
#include "Monster.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Player.h"

Monster::Monster()
{
	for (int i = 0; i < 3; i++)
	{
		Frame[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		Time[i] = 0.f;
	}
	floating = 1.f;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	//FaceTarget(Camera::GetInstance());
	Character::Update();
	
	Billboard();
	OnTerrain();

}

void Monster::Render()
{
	
	Character::Render();
}

void Monster::OnTerrain() {
	GameObject* obj = ObjectManager::GetInstance()->FindObject<Player>();
	Terrain* mesh = (Terrain*)obj->GetComponent(L"Mesh");

	float y;
	bool onTerrain = mesh->GetYFromPoint(&y, transform->position.x, transform->position.z);
	if (onTerrain)
		transform->position.y = y + floating;
	else
	{
		transform->position.y = floating;
	}
}
