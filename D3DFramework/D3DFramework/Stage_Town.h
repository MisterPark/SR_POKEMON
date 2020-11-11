#pragma once
#include "IScene.h"
#include "AllNPC.h"
using namespace PKH;


class Stage_Town :
	public IScene
{
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

public:
	//맵텍스쳐키,높이맵의 파일경로,물의 높이를 인자로 받고 텍스쳐키에 따라 트리를 생성합니다.
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
