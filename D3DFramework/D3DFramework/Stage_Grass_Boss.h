#pragma once
#include "IScene.h"

using namespace PKH;


class Stage_Grass_Boss :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
    void Set_Stage_Grass_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);
};