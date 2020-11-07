#include "stdafx.h"
#include "TitleScene.h"
#include "UI_Title.h"
#include "TestMultiScene.h"
#include "Button.h"
#include "TestScene.h"


void TitleScene::OnLoaded()
{
	//Network::Connect();
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	ObjectManager::GetInstance()->CreateObject<UI_Title>();
	Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"싱글 플레이";
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 600;
	btn->transform->scale = { 3.f,0.5f,1.f };
	btn->Click = SceneManager::LoadScene<TestScene>;

	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"멀티 플레이";
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 650;
	btn->transform->scale = { 3.f,0.5f,1.f };
	btn->SetSize(300, 50);
	btn->Click = SceneManager::LoadScene<TestMultiScene>;

	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"종료";
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 700;
	btn->transform->scale = { 3.f,0.5f,1.f };
	btn->Click = MainGame::Shutdown;
	
	//lobby = LobbyWindow::GetInstance();
	//lobby->Create();
}

void TitleScene::OnUnloaded()
{
	LobbyWindow::Hide();
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


		SceneManager::LoadScene<TestMultiScene>();
		LobbyWindow::Hide();
		break;
	case LobbyResult::CANCEL:
		// 이전 씬으로
		break;
	default:
		break;
	}
}
