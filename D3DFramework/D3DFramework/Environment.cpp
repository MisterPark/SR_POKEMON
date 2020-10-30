#include "stdafx.h"
#include "Environment.h"
#include "Terrain.h"

Environment::Environment()
{
	Initialize();
}


Environment::~Environment()
{
}

void Environment::Initialize()
{
	Terrain* terrain = (Terrain*)AddComponent<PKH::Terrain>(L"Mesh");
	terrain->SetTexture(TextureKey::GRASS_MAP);
	terrain->LoadHeightMap("Texture\\Lake.bmp");
}

void Environment::Release()
{
}

void Environment::Update()
{
	GameObject::Update();
}
