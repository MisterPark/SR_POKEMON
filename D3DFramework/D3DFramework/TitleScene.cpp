#include "stdafx.h"
#include "TitleScene.h"
#include "UI_Title.h"
#include "TestMultiScene.h"
#include "Button.h"
#include "TestScene.h"
#include "SelectScene.h"
#include "Dialog.h"

void TitleScene::OnLoaded()
{
	//Network::Connect();
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	ObjectManager::GetInstance()->CreateObject<UI_Title>();
	Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"�÷���";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 600;
	
	btn->Click = SceneManager::LoadScene<SelectScene>;

	//btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"�ɼ�";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	//btn->transform->position.y = 650;
	//btn->Click = MainGame::Shutdown;

	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"����";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 650;
	btn->Click = MainGame::Shutdown;


	// �׽�Ʈ �� ��
	btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"�׽�Ʈ��";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2) - 300;
	btn->transform->position.y = 600;

	btn->Click = SceneManager::LoadScene<TestScene>;
	
	//lobby = LobbyWindow::GetInstance();
	//lobby->Create();

	Dialog::EnqueueText(L"�ȳ��ϼ���.");
	Dialog::EnqueueText(L"�ݰ����ϴ�.");
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
