#pragma once
#include "UI.h"
class DamageSkin :
    public UI
{
    // UI��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void UpdateUI() override;
};

