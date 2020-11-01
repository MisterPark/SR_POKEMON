#pragma once
#include "IScene.h"

using namespace PKH;


class Stage_Water_01 :
    public IScene
{
    // IScene을(를) 통해 상속됨
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //맵텍스쳐키,높이맵의 파일경로,물의 높이를 인자로 받고 텍스쳐키에 따라 트리를 생성합니다.
    void Set_Stage_Water_01_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);
};
