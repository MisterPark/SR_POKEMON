#pragma once
#include "UI.h"
class UI_Title :
    public UI
{
public:
    UI_Title();
    virtual ~UI_Title();

    // UI��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
};

