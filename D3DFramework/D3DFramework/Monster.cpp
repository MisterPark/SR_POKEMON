#include "stdafx.h"
#include "Monster.h"
#include "Plane.h"
#include "Rectangle.h"

Monster::Monster()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh2");
	
	mesh->SetTexture(TextureKey::CURSOR_TARGET);
	
}

Monster::~Monster()
{
}

void Monster::Update()
{
	//FaceTarget(Camera::GetInstance());
	GameObject::Update();

	Billboard();
	
}

void Monster::Render()
{
	
	GameObject::Render();
}