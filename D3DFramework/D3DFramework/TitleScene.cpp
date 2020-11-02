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
	btn->text = L"�̱� �÷���";
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 600;
	btn->Click = SceneManager::LoadScene<TestScene>;

	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"��Ƽ �÷���";
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 650;
	btn->Click = SceneManager::LoadScene<TestMultiScene>;

	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"����";
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 700;
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
		// �ƹ��ൿ ����
		break;
	case LobbyResult::OK:
		// �г��� üũ �Ѵ��� ��ġ�� �ٽ� ����
		lobby->result = LobbyResult::NONE;


		SceneManager::LoadScene<TestMultiScene>();
		LobbyWindow::Hide();
		break;
	case LobbyResult::CANCEL:
		// ���� ������
		break;
	default:
		break;
	}
}
