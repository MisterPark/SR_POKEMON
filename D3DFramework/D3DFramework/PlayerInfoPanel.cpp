#include "stdafx.h"
#include "PlayerInfoPanel.h"

PlayerInfoPanel* pPlayerInfoPanel = nullptr;

PlayerInfoPanel::PlayerInfoPanel()
{
    Initialize();
}

PlayerInfoPanel::~PlayerInfoPanel()
{
    Release();
}

PlayerInfoPanel* PlayerInfoPanel::GetInstance()
{
    if (pPlayerInfoPanel == nullptr)
    {
        pPlayerInfoPanel = new PlayerInfoPanel;
    }
    return pPlayerInfoPanel;
}

void PlayerInfoPanel::Destroy()
{
    if (pPlayerInfoPanel)
    {
        delete pPlayerInfoPanel;
        pPlayerInfoPanel = nullptr;
    }
}

void PlayerInfoPanel::Show()
{
    pPlayerInfoPanel->isVisible = true;
}

void PlayerInfoPanel::Hide()
{
    pPlayerInfoPanel->isVisible = false;
}

void PlayerInfoPanel::SetTarget(Character* _target)
{
    pPlayerInfoPanel->target = _target;
}

void PlayerInfoPanel::Initialize()
{
}

void PlayerInfoPanel::Release()
{
}

void PlayerInfoPanel::Update()
{
}

void PlayerInfoPanel::Render()
{
    if (pPlayerInfoPanel->isVisible == false) return;
    if (pPlayerInfoPanel->target == nullptr) return;
    if (pPlayerInfoPanel->target->isDead)
    {
        target = nullptr;
        return;
    }

    Vector3 barPos = { 0,0,0 };
    barPos.x = 30;
    barPos.y = dfCLIENT_HEIGHT - 140;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_01, barPos, 0);
    barPos.x += 80;
    barPos.y += 8;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_05, barPos, Vector3(1, 1, 1), 0, float(target->hp) / target->maxHp);
    barPos.x -= 100;
    D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, barPos, int(target->number) - 1);
}
