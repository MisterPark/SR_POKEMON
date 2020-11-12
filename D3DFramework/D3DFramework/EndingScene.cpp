#include "stdafx.h"
#include "AllStage.h"

#include "UI_Title.h"
#include "Button.h"
#include "SkyBox.h"
#include "Dialog.h"
#include "SceneManager.h"
#include "PlayerInfoPanel.h"
void EndingScene::OnLoaded()
{
	SkyBox::Hide();
	PlayerInfoPanel::Hide();
	Player::Hide();

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
	dia->EnqueueText(L"Jusin 110C", L"2조", Pokemon::Celebi);
	dia->EnqueueText(L" 박경훈 팀장, UI, 프레임워크, 아이템&인벤토리,충돌,조명 \n 강희재 플레이어,스킬,사운드,이펙트,응원 \n 길문호 몬스터,스킬,맵,리소스,스토리,퀘스트,스포너,트리거박스 \n 차승현 몬스터,스킬,몬스터AI,NPC, 퀘스트,리소스, 메이플, DJ", L"2조", Pokemon::Celebi);
	dia->EnqueueText(L" 감사합니다", L"2조", Pokemon::Celebi);
	dia->SetEndEvent(NextScene);

}

void EndingScene::OnUnloaded()
{
	LobbyWindow::Hide();
	ObjectManager::DestroyAll();
}

void EndingScene::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		NextScene();
		Dialog::GetInstance()->Destroy();
	}
}

void EndingScene::NextScene()
{
	SceneManager::LoadScene<TitleScene>();
}
