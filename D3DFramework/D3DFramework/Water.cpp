#include "stdafx.h"
#include "Water.h"
#include "Terrain.h"

Water::Water()
{   //TODO : �ҷ��� ����Ÿ����
	Initialize();

}

Water::~Water()
{
}

void Water::Initialize()
{
	Terrain* terrain = (Terrain*)AddComponent<PKH::Terrain>(L"Mesh");
	terrain->SetTexture(TextureKey::WATER_ENVIRONMENT);
	/*terrain->LoadHeightMap("Texture\\Height2_2.bmp");*/
}

void Water::Release()
{
}

void Water::Update()
{

	GameObject::Update();
	
	
}