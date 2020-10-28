#include "stdafx.h"
#include "Monster.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

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
	offsetY = 1.f;
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
	SetTextureAngle();
}

void Monster::Render()
{
	
	Character::Render();
}

void Monster::SetTextureAngle()
{


	float Angle = GetAngleFromCamera();

	//if (Angle < 100) {
	//	int i = 0;
	//}
	Angle += 180.f;
	Angle = int(Angle) / 45;

	if (state == State::WALK) {
		EnumKey = (int)TextureKey::BUTTER_WALK_D_01;
		EnumKey += Angle * 3;
	}
	else {
		EnumKey = (int)TextureKey::BUTTER_ATTACK_D_01;
		EnumKey += Angle * 2;
	}


}

void Monster::SetSpriteWalk()
{
}

void Monster::SetSpriteAttack()
{
}
