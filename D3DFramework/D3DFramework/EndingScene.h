#pragma once
#include "IScene.h"
#include "LobbyWindow.h"

class Label;

class EndingScene :
	public IScene
{
public:
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;



	static void NextScene();

	Label* label1 = nullptr;
	Label* label2 = nullptr;
	Label* label3 = nullptr;
	Label* label4 = nullptr;
	Label* label5 = nullptr;
	Label* label6 = nullptr;
};

