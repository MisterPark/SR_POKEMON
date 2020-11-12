#include "stdafx.h"
#include "AllStage.h"

#include "UI_Title.h"
#include "Button.h"
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
	
	dia->EnqueueText(L"�̾�- ���� ��ٸ��� �߳�!", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���ϸ����� ���迡 �� �Ծ�!", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���� �̸��� ������", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"��ηκ��ʹ� ���������ϸ��̶�� �Ҹ��� �־�.", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���ϸ��͡������ϸ�", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"�� ���迡�� �ʿ� ���� ���ϸ��Ͷ�� �ҷ�����\n����ü���� ��ó�� ����־�!", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���ϸ���� ���ϸ��� ����� �����ų�", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"�Բ� �ο�ų�����", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���� ���Ͱ���", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"��ư��� �־�", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"������ �츮���� ������ ���θ� �˰� ������ ����", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���ϸ��� ����� ������ �ܶ� �ִ°ž�!", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"���� �װ��� �������� ���Ͽ�\n���� ���ϸ��� ������ ����ϰ� �־�!", L"������", Pokemon::Celebi);
	dia->EnqueueText(L"�׷����� ���� ���� �̸��� ������ ��!", L"������", Pokemon::Celebi);
	dia->SetEndEvent(NextScene);
	dia->Show();

}

void Stage_Opening::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void Stage_Opening::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		NextScene();
		Dialog::GetInstance()->Destroy();
	}
	else if (InputManager::GetKeyDown(VK_F4))
	{
		SceneManager::LoadScene<EndingScene>();
		Dialog::GetInstance()->Destroy();
	}
}

void Stage_Opening::NextScene()
{
	SceneManager::LoadScene<SelectScene>();
}
