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
	RenderManager::DrawUI(TextureKey::UI_PROGRESS_PANEL, transform->position,transform->scale, 0);
	Vector3 barPos;
	barPos.x = transform->position.x + (6 * transform->scale.x);
	barPos.y = transform->position.y + (7 * transform->scale.y);
	RenderManager::DrawUI(TextureKey::UI_PROGRESS_BAR, barPos, transform->scale, 0, progress);

}
