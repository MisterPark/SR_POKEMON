#include "stdafx.h"
#include "UI.h"
#include "Rectangle.h"

UI::UI()
{
	
}

UI::~UI()
{
}

void UI::Update()
{
	UpdateUI();
	UpdateEvent();
}

void UI::Render()
{
	D2DRenderManager::DrawUI(textureKey, *transform, 0);

	if (textRenderFlag)
	{
		Vector3 pos = transform->position + textOffsetPosition;
		D2DRenderManager::DrawFont(text, pos.x, pos.y, D3DCOLOR_XRGB(0, 0, 0));
	}
}

void UI::UpdateEvent()
{
	Vector3 cursorPos = Cursor::GetMousePos();

	// Hover & Leave
	if (cursorPos.x > transform->position.x
		&& cursorPos.x < transform->position.x + width
		&& cursorPos.y > transform->position.y
		&& cursorPos.y < transform->position.y + height)
	{
		if (isHover == false)
		{
			OnHover();
		}
		isLeave = false;
		isHover = true;
		
	}
	else
	{
		if (isLeave == false)
		{
			OnLeave();
			isHover = false;
			isLeave = true;
			
		}
	}

	if (InputManager::GetMouseLButton())
	{
		if (isHover)
		{
			OnLButtonDown();
		}
		
	}


}
