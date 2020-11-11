#pragma once
#include "GameObject.h"
class PlayerInfoPanel :
    public GameObject
{
private:
    PlayerInfoPanel();
    virtual ~PlayerInfoPanel();

public:
    static PlayerInfoPanel* GetInstance();
    static void Destroy();

    static void Show();
    static void Hide();

    static void SetTarget(Character* _target);
    static void ActiveRedFilter();
    void UpdateRedFilter();

    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;
    virtual void Render() override;

    static void SetQuestMessage(const wstring& msg);

private:
    Character* target = nullptr;
    
    // 레드필터 전용
    bool isAttacked = false;
    float redTick = 0.f;
    float redDuration = 0.3f;
    bool flashFlag = false;
    float flashTick = 0.f;
    float flashDelay = 0.1f;

    // 퀘스트 전용
    wstring questMessage;
};

