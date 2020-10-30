#include "stdafx.h"
#include "TitleScene.h"
#include "UI_Title.h"
#include "TestMultiScene.h"


void TitleScene::OnLoaded()
{
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);


	ObjectManager::GetInstance()->CreateObject<UI_Title>();

	
	lobby = LobbyWindow::GetInstance();
	lobby->Create();
}

void TitleScene::OnUnloaded()
{
	LobbyWindow::Destroy();
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{
	if (lobby == nullptr) return;

	LobbyResult res = lobby->result;
	switch (res)
	{
	case LobbyResult::NONE:
		// 아무행동 안함
		break;
	case LobbyResult::OK:
		// 닉네임 체크 한다음 겹치면 다시 띄우기
		lobby->result = LobbyResult::NONE;
		
		
		break;
	case LobbyResult::CANCEL:
		// 이전 씬으로
		break;
	default:
		break;
	}
}
