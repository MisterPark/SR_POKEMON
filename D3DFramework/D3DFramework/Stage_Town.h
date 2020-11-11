#pragma once
#include "IScene.h"
#include "AllNPC.h"
using namespace PKH;


class Stage_Town :
	public IScene
{
	// IScene��(��) ���� ��ӵ�
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

public:
	//���ؽ���Ű,���̸��� ���ϰ��,���� ���̸� ���ڷ� �ް� �ؽ���Ű�� ���� Ʈ���� �����մϴ�.
	void Set_Stage_Town_Map(TextureKey _key, const std::string& _filePath, float _waterHeight);
	void Event_Town(Event _event);
	void Event_Game(Event _event);
	static void CreateSpawner();
	static void GrassPortal();
	static void WaterPortal();
	static void FirePortal();

public:
	bool triggerOn = false;
	int spawnerCount = 0;
};
