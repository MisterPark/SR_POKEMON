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
	
	dia->EnqueueText(L"이야- 오래 기다리게 했네!", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"포켓몬스터의 세계에 잘 왔어!", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"나의 이름은 세레비", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"모두로부터는 전설의포켓몬이라고 불리고 있어.", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"포켓몬스터……포켓몬", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"이 세계에는 너와 같은 포켓몬스터라고 불려지는\n생명체들이 도처에 살고있어!", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"포켓몬들은 포켓몬들과 정답게 지내거나", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"함께 싸우거나……", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"서로 도와가며", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"살아가고 있어", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"하지만 우리들은 서로의 전부를 알고 있지는 못해", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"포켓몬의 비밀은 아직도 잔뜩 있는거야!", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"나는 그것을 밝혀내기 위하여\n매일 포켓몬들과 연구를 계속하고 있어!", L"세레비", Pokemon::Celebi);
	dia->EnqueueText(L"그럼…… 슬슬 너의 이름을 가르쳐 줘!", L"세레비", Pokemon::Celebi);
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
