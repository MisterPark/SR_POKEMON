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

    // UI��(��) ���� ��ӵ�
    virtual void OnHover() override;
    virtual void OnLeave() override;
    virtual void OnLButtonDown() override;
    virtual void OnLButtonUp() override;
    virtual void OnClick() override;
};

