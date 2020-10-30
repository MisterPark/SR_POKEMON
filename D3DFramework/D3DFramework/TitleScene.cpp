#include "stdafx.h"
#include "TitleScene.h"
#include "UI_Title.h"
#include "LobbyWindow.h"

void TitleScene::OnLoaded()
{
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);


	ObjectManager::GetInstance()->CreateObject<UI_Title>();

	LobbyWindow lobby =  LobbyWindow::

}

void TitleScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TitleScene::Update()
{
}
