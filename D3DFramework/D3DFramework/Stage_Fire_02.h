#pragma once
#include "IScene.h"

using namespace PKH;


class Stage_Fire_02 :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
    void Set_Stage_Fire_02_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);

    static void Create_Monster_A_Spawner();
    static void Create_Monster_B_Spawner();
    static void Create_Monster_C_Spawner();

	void Stage_Fire_02_Wave();
	static void CreateSpawner();

	static void Portal();
	static void TownPortal();

    static void soHot(float _waterheight);

public:
    float waterHeight = 0.f;
	bool triggerOn = false;
	int spawnerCount = 0;
    float portalDelay = 0.f;
};
