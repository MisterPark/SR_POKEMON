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

void PlayerInfoPanel::ActiveRedFilter()
{
    pPlayerInfoPanel->isAttacked = true;
    pPlayerInfoPanel->redTick = 0.f;
}

void PlayerInfoPanel::UpdateRedFilter()
{
    float dt = TimeManager::DeltaTime();

    if (isAttacked)
    {
        redTick += dt;
        flashTick += dt;
    }

    if (redTick > redDuration)
    {
        redTick = 0.f;
        flashTick = 0.f;
        isAttacked = false;
    }

    
    if (flashTick > flashDelay)
    {
        flashTick = 0.f;
        flashFlag = !flashFlag;
    }
}

void PlayerInfoPanel::Initialize()
{
}

void PlayerInfoPanel::Release()
{
}

void PlayerInfoPanel::Update()
{
    UpdateRedFilter();
}

void PlayerInfoPanel::Render()
{
    if (pPlayerInfoPanel->isVisible == false) return;
    if (pPlayerInfoPanel->target == nullptr) return;
    if (pPlayerInfoPanel->target->IsDead())
    {
        target = nullptr;
        return;
    }

    // 레드 필터 (맞았을떄)
    if (isAttacked)
    {
        if(flashFlag)
            RenderManager::DrawUI(TextureKey::UI_RED_FILTER, Vector3(0, 0, 0), 0);
    }
    
    // HP 바, 아이콘
    Vector3 barPos = { 0,0,0 };
    barPos.x = 100;
    barPos.y = 0;
    RenderManager::DrawUI(TextureKey::UI_HP_BAR_06, barPos, 0);
    barPos.x += 80;
    barPos.y += 8;
    RenderManager::DrawUI(TextureKey::UI_HP_BAR_05, barPos, Vector3(1, 1, 1), 0, float(target->stat.hp) / target->stat.maxHp);
    RenderManager::DrawUI(TextureKey::UI_EXP_BAR_01, Vector3(barPos.x,barPos.y+20,1), Vector3(1, 1, 1), 0, float(target->stat.exp) / target->stat.totalExp);
    
    // 레벨 표시
    WCHAR wstr3[8] = {};
    wsprintf(wstr3, L"Lv.%d", (int)target->stat.level);
    RenderManager::DrawFont(wstr3, barPos.x-60 , barPos.y + 40, D3DCOLOR_ARGB(255, 0, 0, 0));
    //공격력
    RenderManager::DrawUI(TextureKey::UI_ICON_STAT_ATTACK, Vector3(barPos.x+20 ,barPos.y +42,1), 0);
    WCHAR wstr[16] = {};
    wsprintf(wstr, L"%d", (int)target->stat.attack);
    RenderManager::DrawFont(wstr, barPos.x + 50, barPos.y + 40, D3DCOLOR_ARGB(255, 0, 0, 0));
    //스피드
    RenderManager::DrawUI(TextureKey::UI_ICON_STAT_SPEED, Vector3(barPos.x+ 120, barPos.y + 42, 1), 0);

    RenderManager::DrawFont(L"5", barPos.x + 150, barPos.y + 42, D3DCOLOR_ARGB(255, 0, 0, 0));
    // 얼굴
    int pokeNumber = (int)target->number;
    int generation = GetPokemonGeneration(target->number);
    if (generation == 1)
    {
        RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, Vector3(barPos.x - 180, barPos.y - 25, 1), pokeNumber - 1);
    }
    else if (generation == 2)
    {
        pokeNumber -= (int)Pokemon::Mew;
        pokeNumber += 27;//안농 갯수
        RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_2ND, Vector3(barPos.x - 180, barPos.y - 25, 1), pokeNumber - 1);
    }
    else
    {
        pokeNumber -= (int)Pokemon::Celebi;
        RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_3RD, Vector3(barPos.x - 180, barPos.y - 25, 1), pokeNumber - 1);
    }
    
    
    // 스킬 표시
    vector<Skill*> skillSet = target->GetSkillSet();
    int currentSkill = Player::GetInstance()->GetCurrentSkillIndex();
    
    int skillSize = skillSet.size();

    for (int i = 1; i < skillSize; i++)
    {
		// 스킬 아이콘
        Skill* skill = skillSet[i];
        barPos.x = 60 +(i * 80);
        barPos.y = 80;
        RenderManager::DrawUI(skill->GetSkillIcon(), barPos, 0);

        //쿨타임
		float maxCool = skill->GetMaxCoolTime();
        float cool = skill->GetCoolTime();
        bool isCool = skill->GetIsCoolDown();
        if (isCool && cool > 0)
        {
			//쿨타임 필터
			RenderManager::DrawUIHorizontal(TextureKey::UI_BLACK_FILTER, barPos,Vector3(1,1,1), 0,cool/maxCool);
			//쿨타임 폰트
            WCHAR wstr[20] = {};
            wsprintf(wstr, L"%d", (int)(cool+1));
            RenderManager::DrawFont(wstr, barPos.x+25, barPos.y+25, D3DCOLOR_XRGB(255, 255, 255));
        }

		// 아이콘 보더
		if (currentSkill == i)
		{
			RenderManager::DrawUI(TextureKey::UI_ICON_BORDER, Vector3(barPos.x - 8, barPos.y - 8, 0), 0);
		}
    }
    
    // 변신가능 포켓몬 얼굴
    Vector3 facePos;
    facePos.x = 0;
    facePos.y = 150;

    Pokemon metaNum = Player::GetInstance()->GetMetamorphoPokemonNumber();
    int metaNumber = (int)metaNum;
     generation = GetPokemonGeneration(metaNum);
    if (generation == 1)
    {
        RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_1ST, facePos,Vector3(0.5f, 0.5f, 0.5f), metaNumber - 1);
    }
    else if (generation == 2)
    {
        pokeNumber -= (int)Pokemon::Mew;
        pokeNumber += 27;//안농 갯수
        RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_2ND, facePos, Vector3(0.5f, 0.5f, 0.5f), metaNumber - 1);
    }
    else
    {
        pokeNumber -= (int)Pokemon::Celebi;
        RenderManager::DrawUI(TextureKey::UI_FACE_POKEMON_3RD, facePos, Vector3(0.5f, 0.5f, 0.5f), metaNumber - 1);
    }
    
    // 코인 점수

    Vector3 coinPos = { 0,0,0 };
    coinPos.x = 480;
    

    RenderManager::DrawUI(TextureKey::COINPOKE_1, coinPos,Vector3(0.5f, 0.5f, 0.5f), 0);

    coinPos.y = 25;
    WCHAR wstr4[8] = {};
    wsprintf(wstr4, L"%d", target->stat.money);
    RenderManager::DrawFont(wstr4, coinPos.x + 70, coinPos.y, D3DCOLOR_ARGB(255, 0, 0, 0));
    

    // 퀘스트 메세지
    int msgLen = questMessage.length() * 20;
    Vector3 msgPos;
    msgPos.x = dfCLIENT_WIDTH - 160;
    msgPos.y = 150;
    RenderManager::DrawFont(L"퀘스트 메세지", msgPos.x, msgPos.y, D3DCOLOR_ARGB(255, 0, 0, 200));
    msgPos.x = dfCLIENT_WIDTH - msgLen;
    RenderManager::DrawFont(questMessage, msgPos.x, msgPos.y+25, D3DCOLOR_ARGB(255, 0, 0, 100));
}

void PlayerInfoPanel::SetQuestMessage(const wstring& msg)
{
    pPlayerInfoPanel->questMessage = msg;
}

