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
    //���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
    void SetTestSceneMap(TextureKey _key, const std::string& _filePath, float _waterHeight);

	static void CreateSpawner();

	static void Portal();
};
