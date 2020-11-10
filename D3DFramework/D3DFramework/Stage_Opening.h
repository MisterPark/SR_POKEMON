#pragma once
#include "IScene.h"
#include "LobbyWindow.h"

class Stage_Opening :
    public IScene
{
public:
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

    LobbyWindow* lobby = nullptr;
};

