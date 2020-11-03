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

    virtual void Initialize() override;
    virtual void Release() override;
    virtual void Update() override;
    virtual void Render() override;


private:
    Character* target = nullptr;
};

