#pragma once
#include "IScene.h"

using namespace PKH;


class Stage_Fire_01 :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
    void Set_Stage_Fire_01_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);

	void Stage_Fire_01_Wave();
	static void CreateSpawner();
	static void Portal();
	static void TownPortal();
public:
	bool triggerOn = false;
	int spawnerCount = 0;
};
