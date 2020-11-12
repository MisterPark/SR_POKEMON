#pragma once
#include "UI.h"
class ProgressBar :
    public UI
{
public:
    ProgressBar();
    virtual ~ProgressBar();
    // UI을(를) 통해 상속됨
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void UpdateUI() override;
    virtual void Update() override;
    virtual void Render() override;

public:
    float progress = 0.f;
};

