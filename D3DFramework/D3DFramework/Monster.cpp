#include "stdafx.h"
#include "Monster.h"
#include "Plane.h"
#include "Rectangle.h"

Monster::Monster()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Rectangle>(L"Mesh");
	Animation2D* ani = (Animation2D*)AddComponent<Animation2D>(L"Animation2D");

	ani->SetSprite(TextureKey::BUTTER_ATTACK_D_01, TextureKey::BUTTER_ATTACK_D_02);
	ani->SetLoop(true);
	ani->SetDelay(0.5f);
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