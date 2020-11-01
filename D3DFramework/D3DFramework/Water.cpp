#include "stdafx.h"
#include "Water.h"


Water::Water()
{   //TODO : 불렛이 지형타는중
	Initialize();
}

Water::~Water()
{

}

void Water::Initialize()
{
	terrain = (Terrain*)AddComponent<PKH::Terrain>(L"Mesh");
	terrain->SetBlendMode(BlendMode::ALPHA_TEST);
	

	/*terrain->LoadHeightMap("Texture\\Height2_2.bmp");*/
}

void Water::Release()
{
}

void Water::Update()
{

	GameObject::Update();
	
	
}