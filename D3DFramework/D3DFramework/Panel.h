#pragma once
#include "UI.h"
class Panel :
    public UI
{
public:
    Panel();
    virtual ~Panel();
    // UI��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;

    virtual void UpdateUI() override;

    virtual void SetSize(int w, int h);
};

