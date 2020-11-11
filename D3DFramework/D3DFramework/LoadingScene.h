#pragma once
#include "IScene.h"

class Label;

class LoadingScene :
    public IScene
{
public:
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;


    Label* label = nullptr;
};

