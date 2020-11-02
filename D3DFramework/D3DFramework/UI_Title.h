#pragma once
#include "UI.h"
class UI_Title :
    public UI
{
public:
    UI_Title();
    virtual ~UI_Title();

    // UI을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;

    // UI을(를) 통해 상속됨
    virtual void OnHover() override;
    virtual void OnLeave() override;
    virtual void OnLButtonDown() override;
    virtual void OnLButtonUp() override;
    virtual void OnClick() override;
};

