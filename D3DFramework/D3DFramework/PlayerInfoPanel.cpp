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
    barPos.y = 0;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_01, barPos, 0);
    barPos.x += 80;
    barPos.y += 8;
    D2DRenderManager::DrawUI(TextureKey::UI_HP_BAR_05, barPos, Vector3(1, 1, 1), 0, float(target->stat.hp) / target->stat.maxHp);
    barPos.x -= 100;
    D2DRenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, barPos, int(target->number) - 1);

    vector<Skill*> skillSet = target->GetSkillSet();
    int currentSkill = Player::GetInstance()->GetCurrentSkillIndex();
    
    int skillSize = skillSet.size();

    for (int i = 1; i < skillSize; i++)
    {
		

		// 스킬 아이콘
        Skill* skill = skillSet[i];
        barPos.x = 60 +(i * 80);
        barPos.y = 80;
        D2DRenderManager::DrawUI(skill->GetSkillIcon(), barPos, 0);

        //쿨타임
		float maxCool = skill->GetMaxCoolTime();
        float cool = skill->GetCoolTime();
        bool isCool = skill->GetIsCoolDown();
        if (isCool && cool > 0)
        {
			//쿨타임 필터
			D2DRenderManager::DrawUIHorizontal(TextureKey::UI_BLACK_FILTER, barPos,Vector3(1,1,1), 0,cool/maxCool);
			//쿨타임 폰트
            WCHAR wstr[20] = {};
            wsprintf(wstr, L"%d", (int)(cool+1));
            D2DRenderManager::DrawFont(wstr, barPos.x+25, barPos.y+25, D3DCOLOR_XRGB(255, 255, 255));
        }

		// 아이콘 보더
		if (currentSkill == i)
		{
			D2DRenderManager::DrawUI(TextureKey::UI_ICON_BORDER, Vector3(barPos.x - 8, barPos.y - 8, 0), 0);
		}
    }
    
   
    
    
}
