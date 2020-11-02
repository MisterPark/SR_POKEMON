#include "stdafx.h"
#include "TestMultiScene.h"

void TestMultiScene::OnLoaded()
{
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 1);

}

void TestMultiScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TestMultiScene::Update()
{
}
