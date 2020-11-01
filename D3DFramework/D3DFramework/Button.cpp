#include "stdafx.h"
#include "Button.h"
#include "TestScene.h"

Button::Button()
{
	transform->scale = { 3.f,0.5f,1.f };
	textureKey = TextureKey::UI_BUTTON;
	textRenderFlag = true;
	text = L"¹öÆ°";
	textOffsetPosition = { 20,10,0 };
	originScale = transform->scale;
	UpdateUI();
}

Button::~Button()
{
}

void Button::Initialize()
{
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
	if (!isUpScale)
	{
		isUpScale = true;
		transform->scale *= upScaleRatio;
	}
	
	
}

void Button::OnLeave()
{
	if (isUpScale)
	{
		isUpScale = false;
		transform->scale = originScale;
	}
}

void Button::OnLButtonDown()
{
	if (!isButtonDown)
	{
		isButtonDown = true;
		transform->position.x += 5;
		transform->position.y += 5;
		SceneManager::LoadScene<TestScene>();
	}
}

void Button::OnLButtonUp()
{
}

void Button::OnLButtonClick()
{
	SceneManager::LoadScene<TestScene>();
}
