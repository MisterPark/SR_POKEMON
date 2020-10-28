#include "stdafx.h"
#include "UI_Title.h"

UI_Title::UI_Title()
{
	Initialize();
}

UI_Title::~UI_Title()
{
	Release();
}

void UI_Title::Initialize()
{
	transform->scale = { (float)dfCLIENT_WIDTH / dfCLIENT_HEIGHT,1,1 };
	Mesh* mesh = (Mesh*)GetComponent(L"Mesh");
	mesh->SetTexture(TextureKey::TITLE_SCREEN);
}

void UI_Title::Release()
{
}
