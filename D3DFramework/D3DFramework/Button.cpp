#include "stdafx.h"
#include "Button.h"
Button::Button()
{
	Initialize();
}

Button::~Button()
{
	Release();
}

void Button::Initialize()
{
	transform->scale = { 3.f,0.5f,1.f };
	textureKey = TextureKey::UI_BUTTON;
	textRenderFlag = true;
	text = L"¹öÆ°";
	textOffsetPosition = { 20,10,0 };
	originScale = transform->scale;
	
	UpdateUI();
}

void Button::Release()
{
}

void Button::Update()
{
	
	UI::Update();

}

void Button::UpdateUI()
{
	width = transform->scale.x * 88;
	height = transform->scale.y * 88;

	int len = lstrlenW(text.c_str());
	int strW = 20;
	int strH = 25;
	
	textOffsetPosition.x = (width / 2) - ((len / 2.f) * strW);
	textOffsetPosition.y = (height / 2) - (strH / 2);
}

void Button::OnHover()
{
	UI::OnHover();

	if (!isUpScale)
	{
		isUpScale = true;
		transform->scale *= upScaleRatio;
	}
	
	
}

void Button::OnLeave()
{
	UI::OnLeave();

	if (isUpScale)
	{
		isUpScale = false;
		transform->scale = originScale;
	}
	
}

void Button::OnLButtonDown()
{
	UI::OnLButtonDown();

	if (!isButtonDown)
	{
		isButtonDown = true;
		originPosition = transform->position;
		transform->position.x += 5;
		transform->position.y += 5;
	}
	
}

void Button::OnLButtonUp()
{
	if (isButtonDown)
	{
		isButtonDown = false;
		transform->position = originPosition;
	}
	
	UI::OnLButtonUp();
}

void Button::OnClick()
{
	UI::OnClick();
}
