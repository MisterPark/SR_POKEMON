#include "stdafx.h"
#include "LoadingScene.h"
#include "Stage_Opening.h"
#include "Label.h"

void LoadingScene::OnLoaded()
{
	label = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	//label->text = L"Å×½ºÆ®";

	LoadManager::LoadResources();

	
}

void LoadingScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void LoadingScene::Update()
{
	if (label != nullptr)
	{
		label->text = LoadManager::GetText();
	}

	if (LoadManager::IsFinish())
	{
		
		if (InputManager::GetKeyDown(VK_RETURN))
		{
			SceneManager::LoadScene<Stage_Opening>();
		}
	}
}
