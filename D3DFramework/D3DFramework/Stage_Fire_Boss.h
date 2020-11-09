#pragma once
#include "IScene.h"

using namespace PKH;


class Stage_Fire_Boss :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
    void Set_Stage_Fire_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);

    void Stage_Fire_Boss_Wave();
    static void CreateSpawner();
	static void TownPortal();
    static void soHot(float _waterheight);
public:
    float waterHeight = 0.f;
    bool triggerOn = false;
    int spawnerCount = 0;
};
