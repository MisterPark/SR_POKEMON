#include "stdafx.h"
#include "AllStage.h"

#include "UI_Title.h"
#include "Button.h"
#include "SkyBox.h"
#include "Dialog.h"
#include "SceneManager.h"
#include "PlayerInfoPanel.h"
#include "Label.h"
void EndingScene::OnLoaded()
{
	SkyBox::Hide();
	PlayerInfoPanel::Hide();
	Player::Hide();
	SoundManager::StopAll();
	SoundManager::PlayBGM(L"Ending.wav");
	

	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

	// UI
	UI_Title* ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_ENDING_SCENE);

	float size = 1.3f;
	ui->transform->scale = { size,size,size };

	int len = 250;

	label1 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label1->text = L"Jusin 110C 2��";
	label1->transform->position.x = 400;
	label1->transform->position.y = dfCLIENT_HEIGHT + 30;
	label1->transform->scale = { 2,2,2 };
	

	label2 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label2->text = L"���� �ڰ��� : �����ӿ�ũ, �浹, UI, ������&�κ��丮, ����";
	label2->transform->position.x = len - 47;
	label2->transform->position.y = dfCLIENT_HEIGHT + 170;
	

	label3 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label3->text = L"������ : �÷��̾�, ��ų, ����, ����Ʈ, ī�޶� ";
	label3->transform->position.x = len;
	label3->transform->position.y = dfCLIENT_HEIGHT + 200;
	

	label4 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label4->text = L"�湮ȣ : ����, ��ų, ��, ���ҽ�, ���丮, ����Ʈ, ������, Ʈ���Źڽ�";
	label4->transform->position.x = len;
	label4->transform->position.y = dfCLIENT_HEIGHT + 230;
	

	label5 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label5->text = L"������ : ����, ��ų, ����AI, NPC, ����Ʈ, ���ҽ�";
	label5->transform->position.x = len;
	label5->transform->position.y = dfCLIENT_HEIGHT + 260;
	

	label6 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label6->text = L"�����մϴ�!!!";
	label6->transform->position.x = 420;
	label6->transform->position.y = dfCLIENT_HEIGHT + 450;
	label6->transform->scale = { 2,2,2 };
	/*Dialog* dia = Dialog::GetInstance();
	dia->Show();
	dia->EnqueueText(L"", L"2��", Pokemon::Celebi);
	dia->EnqueueText(L"  \n \n  \n ", L"2��", Pokemon::Celebi);
	dia->EnqueueText(L" �����մϴ�", L"2��", Pokemon::Celebi);
	dia->SetEndEvent(NextScene);*/

}

void EndingScene::OnUnloaded()
{
	LobbyWindow::Hide();
	ObjectManager::DestroyAll();
}

void EndingScene::Update()
{
	float dt = TimeManager::DeltaTime();
	label1->transform->position.y -= 30.f * dt;
	label2->transform->position.y -= 30.f * dt;
	label3->transform->position.y -= 30.f * dt;
	label4->transform->position.y -= 30.f * dt;
	label5->transform->position.y -= 30.f * dt;
	label6->transform->position.y -= 30.f * dt;

	if (label1->transform->position.y < -430.f)
	{
		label1->transform->position.y = dfCLIENT_HEIGHT;
	}
	if (label2->transform->position.y < -430.f)
	{
		label2->transform->position.y = dfCLIENT_HEIGHT;
	}
	if (label3->transform->position.y < -430.f)
	{
		label3->transform->position.y = dfCLIENT_HEIGHT;
	}
	if (label4->transform->position.y < -430.f)
	{
		label4->transform->position.y = dfCLIENT_HEIGHT;
	}
	if (label5->transform->position.y < -430.f)
	{
		label5->transform->position.y = dfCLIENT_HEIGHT;
	}
	if (label6->transform->position.y < -430.f)
	{
		label6->transform->position.y = dfCLIENT_HEIGHT;
	}



	if (InputManager::GetKeyDown(VK_ESCAPE))
	{
		MainGame::Shutdown();
	}
}

void EndingScene::NextScene()
{
	SceneManager::LoadScene<TitleScene>();
}
