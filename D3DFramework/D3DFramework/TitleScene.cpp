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
	Cursor::Show();
	SoundManager::PlayBGM(L"Title.wav");
	SoundManager::SetVolume(SoundChannel::BGM, 0.1f);

	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	ObjectManager::GetInstance()->CreateObject<UI_Title>();
	Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"플레이";
	btn->SetSize(250, 40);
	btn->transform->position.x = float((dfCLIENT_WIDTH / 2) - (btn->width / 2));
	btn->transform->position.y = 600;
	btn->Click = SceneManager::LoadScene<LoadingScene>;


	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"종료";
	btn->SetSize(250, 40);
	btn->transform->position.x = float((dfCLIENT_WIDTH / 2) - (btn->width / 2));
	btn->transform->position.y = 650;
	btn->Click = MainGame::Shutdown;

	

	Dialog::GetInstance()->Hide();
}

void TitleScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{
}
