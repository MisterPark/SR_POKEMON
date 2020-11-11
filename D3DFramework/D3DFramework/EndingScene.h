#pragma once
#include "IScene.h"
#include "LobbyWindow.h"

class EndingScene :
    public IScene
{
public:
    // IScene을(를) 통해 상속됨
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

    LobbyWindow* lobby = nullptr;

    static void NextScene();
};

