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
	Dialog::EnqueueText(L"이야- 오래 기다리게 했다!");
	Dialog::EnqueueText(L"포켓몬스터의 세계에 잘왔단다!");
	Dialog::EnqueueText(L"나의 이름은 오박사");
	Dialog::EnqueueText(L"모두로부터는 포켓몬박사라고 존경받고 있단다.");
	Dialog::EnqueueText(L"포켓몬스터……포켓몬");
	Dialog::EnqueueText(L"이 세계에는 포켓몬스터라고 불려지는 생명체들이 도처에 살고있다!");
	Dialog::EnqueueText(L"사람은 포켓몬들과 정답게 지내거나");
	Dialog::EnqueueText(L"함께 싸우거나……");
	Dialog::EnqueueText(L"서로 도와가며");
	Dialog::EnqueueText(L"살아가고 있단다");
	Dialog::EnqueueText(L"하지만 우리들은 포켓몬 전부를 알고 있지는 못하다");
	Dialog::EnqueueText(L"포켓몬의 비밀은 아직도 잔뜩 있다!");
	Dialog::EnqueueText(L"나는 그것을 밝혀내기 위하여 매일 포켓몬의 연구를 계속하고 있다는 말이다!");
	Dialog::EnqueueText(L"모험을 시작해보자!");


	//Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"플레이";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	//btn->transform->position.y = 600;

	//btn->Click = SceneManager::LoadScene<SelectScene>;

	////btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	////btn->text = L"옵션";
	////btn->SetSize(250, 40);
	////btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	////btn->transform->position.y = 650;
	////btn->Click = MainGame::Shutdown;

	//btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"종료";
	//btn->SetSize(250, 40);
	//btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	//btn->transform->position.y = 650;
	//btn->Click = MainGame::Shutdown;


	//// 테스트 씬 용
	//btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	//btn->text = L"테스트씬";
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
		// 아무행동 안함
		break;
	case LobbyResult::OK:
		// 닉네임 체크 한다음 겹치면 다시 띄우기
		lobby->result = LobbyResult::NONE;


		SceneManager::LoadScene<TestMultiScene>();
		LobbyWindow::Hide();
		break;
	case LobbyResult::CANCEL:
		// 이전 씬으로
		break;
	default:
		break;
	}
}
