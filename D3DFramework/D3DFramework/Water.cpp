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
	anim = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");


	anim->SetSprite(TextureKey::WATER_WATER_ENVIRONMENT01, TextureKey::WATER_WATER_ENVIRONMENT03);
	anim->SetDelay(1.f);
	anim->SetLoop(true);

	
		
	
}

void Water::Release()
{
}

void Water::Update()
{

	GameObject::Update();
	
	
}

void Water::Lava()
{
	anim->SetSprite(TextureKey::FIRE_WATER_ENVIRONMENT02, TextureKey::FIRE_WATER_ENVIRONMENT02);
	anim->SetLoop(false);
}
