#include "stdafx.h"
#include "Stage_Opening.h"
#include "UI_Title.h"
#include "TestMultiScene.h"
#include "Button.h"
#include "TestScene.h"
#include "SelectScene.h"
#include "Dialog.h"
#include "SceneManager.h"

void Stage_Opening::OnLoaded()
{
	//Network::Connect();
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	UI_Title* ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_DROH_SCREEN);
	ui->transform->position.x = 330.f;
	ui->transform->position.y = 300.f;
	float size = 2.f;
	ui->transform->scale = { size,size,size };
	
	Dialog* dia = Dialog::GetInstance();
	dia->Show();
	dia->EnqueueText(L"�̾�- ���� ��ٸ��� �ߴ�!");
	dia->EnqueueText(L"���ϸ����� ���迡 �߿Դܴ�!");
	dia->EnqueueText(L"���� �̸��� ���ڻ�");
	dia->EnqueueText(L"��ηκ��ʹ� ���ϸ�ڻ��� ����ް� �ִܴ�.");
	dia->EnqueueText(L"���ϸ��͡������ϸ�");
	dia->EnqueueText(L"�� ���迡�� �ʿ� ���� ���ϸ��Ͷ�� �ҷ����� ����ü���� ��ó�� ����ִ�!");
	dia->EnqueueText(L"���ϸ���� ���ϸ��� ����� �����ų�");
	dia->EnqueueText(L"�Բ� �ο�ų�����");
	dia->EnqueueText(L"���� ���Ͱ���");
	dia->EnqueueText(L"��ư��� �ִܴ�");
	dia->EnqueueText(L"������ �츮���� ���ϸ� ���θ� �˰� ������ ���ϴ�");
	dia->EnqueueText(L"���ϸ��� ����� ������ �ܶ� �ִ�!");
	dia->EnqueueText(L"���� �װ��� �������� ���Ͽ� ���� ���ϸ��� ������ ����ϰ� �ִٴ� ���̴�!");
	dia->EnqueueText(L"�׷����� ���� ���� �̸��� �����Ĵٿ�!");
	dia->SetEndEvent(NextScene);

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

void Stage_Opening::NextScene()
{
	SceneManager::LoadScene<SelectScene>();
}
