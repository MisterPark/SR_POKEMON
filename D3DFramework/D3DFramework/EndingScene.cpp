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
	dia->EnqueueText(L"Jusin 110C", L"2��", Pokemon::Celebi);
	dia->EnqueueText(L" �ڰ��� ����, UI, �����ӿ�ũ, ������&�κ��丮,�浹,���� \n ������ �÷��̾�,��ų,����,����Ʈ,���� \n �湮ȣ ����,��ų,��,���ҽ�,���丮,����Ʈ,������,Ʈ���Źڽ� \n ������ ����,��ų,����AI,NPC, ����Ʈ,���ҽ�, ������, DJ", L"2��", Pokemon::Celebi);
	dia->EnqueueText(L" �����մϴ�", L"2��", Pokemon::Celebi);
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
