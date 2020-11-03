#include "stdafx.h"
#include "TargetInfoPanel.h"
#include "UI.h"
#include "Panel.h"
#include "Character.h"

TargetInfoPanel* pTargetInfoPanel = nullptr;

TargetInfoPanel::TargetInfoPanel()
{
    Initialize();
}

TargetInfoPanel::~TargetInfoPanel()
{
    Release();
}

TargetInfoPanel* TargetInfoPanel::GetInstance()
{
    if (pTargetInfoPanel == nullptr)
    {
        pTargetInfoPanel = new TargetInfoPanel;
    }
    return pTargetInfoPanel;
}

void TargetInfoPanel::Destroy()
{
    if (pTargetInfoPanel)
    {
        delete pTargetInfoPanel;
        pTargetInfoPanel = nullptr;
    }
}

void TargetInfoPanel::Show()
{
    pTargetInfoPanel->isVisible = true;
}

void TargetInfoPanel::Hide()
{
    pTargetInfoPanel->isVisible = false;
}

void TargetInfoPanel::SetTarget(Character* _target)
{
    pTargetInfoPanel->target = _target;
    pTargetInfoPanel->activationTick = 0.f;
}

void TargetInfoPanel::Initialize()
{
    isVisible = false;
}

void TargetInfoPanel::Release()
{
}

void TargetInfoPanel::Update()
{
    activationTick += TimeManager::DeltaTime();
    if (activationTick > activationDuration)
    {
        isVisible = false;
    }
}

void TargetInfoPanel::Render()
{
    if (pTargetInfoPanel->isVisible == false) return;
    if (pTargetInfoPanel->target == nullptr) return;
    if (pTargetInfoPanel->target->isDead)
    {
        target = nullptr;
        return;
    }


    Vector3 barPos = { 0,0,0 };
    barPos.x = dfCLIENT_WIDTH - 320;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_01, barPos, 0);
    barPos.x += 80;
    barPos.y += 8;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_05, barPos,Vector3(1,1,1), 0,float(target->hp)/target->maxHp);
    barPos.x -= 100;
    D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, barPos, int(target->number)-1);
}
