#pragma once
#include "IScene.h"

using namespace PKH;


class Stage_Water_Boss :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

public:
    //���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
    void Set_Stage_Water_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);

	static void Create_Monster_A_Spawner();
	static void Create_Monster_B_Spawner();
	static void Create_Monster_C_Spawner();
};
