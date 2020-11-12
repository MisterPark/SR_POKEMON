#include "stdafx.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar()
{
}

ProgressBar::~ProgressBar()
{
}

void ProgressBar::Initialize()
{
}

void ProgressBar::Release()
{
}

void ProgressBar::UpdateUI()
{
}

void ProgressBar::Update()
{
	UI::Update();
}

void ProgressBar::Render()
{
	RenderManager::DrawUI(TextureKey::UI_PROGRESS_PANEL, transform->position, 0);
	Vector3 barPos;
	barPos.x = transform->position.x + 6;
	barPos.y = transform->position.y + 7;
	RenderManager::DrawUI(TextureKey::UI_PROGRESS_BAR, barPos, Vector3(1, 1, 1), 0, progress);

}
