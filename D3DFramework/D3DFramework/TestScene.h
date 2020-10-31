#pragma once
#include "IScene.h"

using namespace PKH;


class TestScene :
    public IScene
{
    // IScene을(를) 통해 상속됨
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //맵텍스쳐,높이맵,임의의 트리
    void SetTestSceneMap(TextureKey _key, const std::string& _filePath);
};
