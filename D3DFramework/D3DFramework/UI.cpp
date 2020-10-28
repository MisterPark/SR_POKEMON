#include "stdafx.h"
#include "UI.h"
#include "Rectangle.h"

UI::UI()
{
	transform->position = { 0,0,1 };
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	
	
}

UI::~UI()
{
}

void UI::Update()
{
	GameObject::Update();
	//Billboard();
}
