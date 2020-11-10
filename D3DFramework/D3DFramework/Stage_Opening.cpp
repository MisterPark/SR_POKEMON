#include "stdafx.h"
#include "Stage_Opening.h"
#include "UI_Title.h"
#include "TestMultiScene.h"
#include "Button.h"
#include "TestScene.h"
#include "SelectScene.h"
#include "Dialog.h"

void Stage_Opening::OnLoaded()
{
	//Network::Connect();
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	UI_Title* ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_DROH_SCREEN);
	ui->transform->position.x = 400.f;
	ui->transform->position.y = 300.f;

	
	Dialog::GetInstance()->Show();
	Dialog::EnqueueText(L"�̾�- ���� ��ٸ��� �ߴ�!");
	Dialog::EnqueueText(L"���ϸ����� ���迡 �߿Դܴ�!");
	Dialog::EnqueueText(L"���� �̸��� ���ڻ�");
	Dialog::EnqueueText(L"��ηκ��ʹ� ���ϸ�ڻ��� ����ް� �ִܴ�.");
	Dialog::EnqueueText(L"���ϸ��͡������ϸ�");
	Dialog::EnqueueText(L"�� ���迡�� ���ϸ��Ͷ�� �ҷ����� ����ü���� ��ó�� ����ִ�!");
	Dialog::EnqueueText(L"����� ���ϸ��� ����� �����ų�");
	Dialog::EnqueueText(L"�Բ� �ο�ų�����");
	Dialog::EnqueueText(L"���� ���Ͱ���");
	Dialog::EnqueueText(L"��ư��� �ִܴ�");
	Dialog::EnqueueText(L"������ �츮���� ���ϸ� ���θ� �˰� ������ ���ϴ�");
	Dialog::EnqueueText(L"���ϸ��� ����� ������ �ܶ� �ִ�!");
	Dialog::EnqueueText(L"���� �װ��� �������� ���Ͽ� ���� ���ϸ��� ������ ����ϰ� �ִٴ� ���̴�!");
	Dialog::EnqueueText(L"������ �����غ���!");


	//Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"�÷���";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	//btn->transform->position.y = 600;

	//btn->Click = SceneManager::LoadScene<SelectScene>;

	////btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	////btn->text = L"�ɼ�";
	////btn->SetSize(250, 40);
	////btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	////btn->transform->position.y = 650;
	////btn->Click = MainGame::Shutdown;

	//btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"����";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	//btn->transform->position.y = 650;
	//btn->Click = MainGame::Shutdown;


	//// �׽�Ʈ �� ��
	//btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"�׽�Ʈ��";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2) - 300;
	//btn->transform->position.y = 600;

	//btn->Click = SceneManager::LoadScene<TestScene>;

	//lobby = LobbyWindow::GetInstance();
	//lobby->Create();

	/*Dialog::GetInstance()->Hide();*/
}

void Stage_Opening::OnUnloaded()
{
	LobbyWindow::Hide();
	ObjectManager::DestroyAll();
}

void Stage_Opening::Update()
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
