#include "stdafx.h"
#include "UI_Title.h"

UI_Title::UI_Title()
{
	Initialize();
	textureKey = TextureKey::UI_TITLE_SCREEN;
}

UI_Title::~UI_Title()
{
	Release();
}

void UI_Title::Initialize()
{
	//transform->scale = { (float)dfCLIENT_WIDTH / dfCLIENT_HEIGHT,1,1 };

}

void UI_Title::Release()
{
}

void UI_Title::OnHover()
{
}

void UI_Title::OnLeave()
{
}

void UI_Title::OnLButtonDown()
{
}

void UI_Title::OnLButtonUp()
{
}

void UI_Title::OnLButtonClick()
{
}
