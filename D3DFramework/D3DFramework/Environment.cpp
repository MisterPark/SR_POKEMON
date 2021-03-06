#include "stdafx.h"
#include "Environment.h"


Environment::Environment()
{
	Initialize();
}


Environment::~Environment()
{
}

void Environment::Initialize()
{
	terrain = (Terrain*)AddComponent<PKH::Terrain>(L"Mesh");
	terrain->SetLightMode(LightMode::ON);
	//terrain->SetTexture(TextureKey::GRASS_MAP);
	//terrain->LoadHeightMap("Texture\\Lake.bmp");
}

void Environment::Release()
{
}

void Environment::Update()
{
	GameObject::Update();
}

void Environment::Render()
{
	
	GameObject::Render();
	
	
}
