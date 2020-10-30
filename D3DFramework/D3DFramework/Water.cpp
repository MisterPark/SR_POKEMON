#include "stdafx.h"
#include "Water.h"
#include "Rectangle.h"
#include "Player.h"
#include "Effect.h"

Water::Water()
{   //TODO : 불렛이 지형타는중
	SetTexture(State::IDLE, TextureKey::WATER_ENVIRONMENT, 1);
	UpdateAnimation();
	state = State::IDLE;
	anim->SetLoop(true);
	anim->SetDelay(0.2f);

	for (int i = 0; i < 3; i++)
	{
		Time[i] = 0;
	}
	transform->position.x = dfTERRAIN_WIDTH / 2;
	transform->position.y = 8.5f;
	transform->position.z = dfTERRAIN_HEIGHT / 2;

	transform->scale.x = 25.f;
	transform->scale.y = 25.f;
	transform->scale.z = 25.f;

	transform->eulerAngles.x=D3DXToRadian(90);
	moveSpeed = 0.f;
}

Water::~Water()
{
}

void Water::Update()
{

	Effect::Update();
	
	
}

void Water::Render()
{
	Effect::Render();
}
