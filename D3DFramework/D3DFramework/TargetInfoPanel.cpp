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
    if (pTargetInfoPanel->target->IsDead())
    {
        target = nullptr;
        return;
    }


    Vector3 barPos = { 0,0,0 };
    barPos.x = dfCLIENT_WIDTH - 320;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_01, barPos, 0);
    barPos.x += 80;
    barPos.y += 8;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_05, barPos,Vector3(1,1,1), 0,float(target->stat.hp)/target->stat.maxHp);
    barPos.x -= 100;

    // ¾ó±¼
    int pokeNumber = (int)target->number;
    int generation = GetPokemonGeneration(target->number);
    if (generation == 1)
    {
        D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, barPos, pokeNumber - 1);
    }
    else if (generation == 2)
    {
        pokeNumber -= (int)Pokemon::Mew;
        pokeNumber += 27;//¾È³ó °¹¼ö
        D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_2ND, barPos, pokeNumber - 1);
    }
    else
    {
        pokeNumber -= (int)Pokemon::Celebi;
        D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_3RD, barPos, pokeNumber - 1);
    }

    // ·¹º§ Ç¥½Ã
    WCHAR wstr3[8] = {};
    wsprintf(wstr3, L"Lv.%d", (int)target->stat.level);
    D2DRenderManager::DrawFont(wstr3, barPos.x + 150, barPos.y + 90, D3DCOLOR_ARGB(255, 255, 255, 255));
}
