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
    barPos.y = dfCLIENT_HEIGHT - 150;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_01, barPos, 0);
    barPos.x += 80;
    barPos.y += 8;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_05, barPos, Vector3(1, 1, 1), 0, float(target->hp) / target->maxHp);
    barPos.x -= 100;
    D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, barPos, int(target->number) - 1);

    vector<Skill*> skillSet = target->GetSkillSet();
    int currentSkill = Player::GetInstance()->GetCurrentSkillIndex();
    
    int skillSize = skillSet.size();

    for (int i = 1; i < skillSize; i++)
    {
        Skill* skill = skillSet[i];
        barPos.x = 60 +(i * 80);
        barPos.y = dfCLIENT_HEIGHT - 80;
        D2DRenderManager::DrawUI(skill->GetSkillIcon(), barPos, 0);

        //ÄðÅ¸ÀÓ
        int cool = (int)skill->GetCoolTime();
        bool isCool = skill->GetIsCoolDown();
        if (isCool && cool > 0)
        {
            WCHAR wstr[20] = {};
            wsprintf(wstr, L"%d", cool);
            D2DRenderManager::DrawFont(wstr, barPos.x+25, barPos.y+25, D3DCOLOR_XRGB(0, 0, 0));
        }

        if (currentSkill == i)
        {
            D2DRenderManager::DrawUI(TextureKey::UI_ICON_BORDER, barPos, 0);
        }
    }
    
   
    
    
}
