#include "stdafx.h"
#include "AllStage.h"
#include "UI_Title.h"
#include "TestMultiScene.h"
#include "Button.h"
#include "TestScene.h"
#include "SelectScene.h"
#include "Dialog.h"
#include "LoadingScene.h"

void TitleScene::OnLoaded()
{
	SoundManager::PlayBGM(L"Title.wav");
	SoundManager::SetVolume(SoundChannel::BGM, 0.1f);

	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	ObjectManager::GetInstance()->CreateObject<UI_Title>();
	Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"플레이";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 600;
	
	btn->Click = SceneManager::LoadScene<LoadingScene>;

	//btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"옵션";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	//btn->transform->position.y = 650;
	//btn->Click = MainGame::Shutdown;

	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"종료";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 650;
	btn->Click = MainGame::Shutdown;


	// 테스트 씬 용
	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"테스트씬";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2) - 300;
	btn->transform->position.y = 600;

	btn->Click = SceneManager::LoadScene<TestScene>;
	

	Dialog::GetInstance()->Hide();
}

void TitleScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{
}
