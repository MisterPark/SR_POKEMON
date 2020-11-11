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
	ui->SetTexture(TextureKey::UI_CELEBI_SCREEN);
	ui->transform->position.x = 500.f;
	ui->transform->position.y = 150.f;
	float size = 2.f;
	ui->transform->scale = { size,size,size };
	
	Dialog* dia = Dialog::GetInstance();
	dia->Show();
	dia->EnqueueText(L"�̾�- ���� ��ٸ��� �߳�!");
	dia->EnqueueText(L"���ϸ����� ���迡 �� �Ծ�!");
	dia->EnqueueText(L"���� �̸��� ������");
	dia->EnqueueText(L"��ηκ��ʹ� ���������ϸ��̶�� �Ҹ��� �־�.");
	dia->EnqueueText(L"���ϸ��͡������ϸ�");
	dia->EnqueueText(L"�� ���迡�� �ʿ� ���� ���ϸ��Ͷ�� �ҷ����� ����ü���� ��ó�� ����־�!");
	dia->EnqueueText(L"���ϸ���� ���ϸ��� ����� �����ų�");
	dia->EnqueueText(L"�Բ� �ο�ų�����");
	dia->EnqueueText(L"���� ���Ͱ���");
	dia->EnqueueText(L"��ư��� �־�");
	dia->EnqueueText(L"������ �츮���� ������ ���θ� �˰� ������ ����");
	dia->EnqueueText(L"���ϸ��� ����� ������ �ܶ� �ִ°ž�!");
	dia->EnqueueText(L"���� �װ��� �������� ���Ͽ� ���� ���ϸ��� ������ ����ϰ� �־�!");
	dia->EnqueueText(L"�׷����� ���� ���� �̸��� ������ ��!");
	dia->SetEndEvent(NextScene);

}

void Stage_Opening::OnUnloaded()
{
	LobbyWindow::Hide();
	ObjectManager::DestroyAll();
}

void Stage_Opening::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		NextScene();
		Dialog::GetInstance()->Destroy();
	}
}

void Stage_Opening::NextScene()
{
	SceneManager::LoadScene<SelectScene>();
}
