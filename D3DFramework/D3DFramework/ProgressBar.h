#pragma once
#include "UI.h"
class ProgressBar :
    public UI
{
public:
    ProgressBar();
    virtual ~ProgressBar();
    // UI��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
    virtual void UpdateUI() override;
    virtual void Update() override;
    virtual void Render() override;

public:
    float progress = 0.f;
};

