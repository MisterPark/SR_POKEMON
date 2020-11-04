#pragma once
#include "UI.h"
class DamageSkin :
    public UI
{
    // UI을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void UpdateUI() override;
};

