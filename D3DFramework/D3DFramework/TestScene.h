#pragma once
#include "IScene.h"

using namespace PKH;


class TestScene :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //���ؽ���,���̸�,������ Ʈ��
    void SetTestSceneMap(TextureKey _key, const std::string& _filePath);
};
