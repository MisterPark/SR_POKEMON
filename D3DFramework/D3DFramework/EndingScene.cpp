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
	label1->text = L"Jusin 110C 2조";
	label1->transform->position.x = 400;
	label1->transform->position.y = dfCLIENT_HEIGHT + 30;
	label1->transform->scale = { 2,2,2 };
	

	label2 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label2->text = L"팀장 박경훈 : 프레임워크, 충돌, UI, 아이템&인벤토리, 조명";
	label2->transform->position.x = len - 47;
	label2->transform->position.y = dfCLIENT_HEIGHT + 170;
	

	label3 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label3->text = L"강희재 : 플레이어, 스킬, 사운드, 이펙트, 카메라 ";
	label3->transform->position.x = len;
	label3->transform->position.y = dfCLIENT_HEIGHT + 200;
	

	label4 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label4->text = L"길문호 : 몬스터, 스킬, 맵, 리소스, 스토리, 퀘스트, 스포너, 트리거박스";
	label4->transform->position.x = len;
	label4->transform->position.y = dfCLIENT_HEIGHT + 230;
	

	label5 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label5->text = L"차승현 : 몬스터, 스킬, 몬스터AI, NPC, 퀘스트, 리소스";
	label5->transform->position.x = len;
	label5->transform->position.y = dfCLIENT_HEIGHT + 260;
	

	label6 = (Label*)ObjectManager::GetInstance()->CreateObject<Label>();
	label6->text = L"감사합니다!!!";
	label6->transform->position.x = 420;
	label6->transform->position.y = dfCLIENT_HEIGHT + 450;
	label6->transform->scale = { 2,2,2 };
	/*Dialog* dia = Dialog::GetInstance();
	dia->Show();
	dia->EnqueueText(L"", L"2조", Pokemon::Celebi);
	dia->EnqueueText(L"  \n \n  \n ", L"2조", Pokemon::Celebi);
	dia->EnqueueText(L" 감사합니다", L"2조", Pokemon::Celebi);
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
