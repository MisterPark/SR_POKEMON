#include "stdafx.h"
#include "TestMultiScene.h"
#include "SkyBox.h"
#include "AllCharacters.h"
#include "Button.h"

bool TestMultiScene::isClickedRotateButton = false;
float TestMultiScene::rotationAngle = 0.f;

void TestMultiScene::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYBLUE1_U);
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3::LEFT;

	//Network::Connect();

	pokeA = (Character*)ObjectManager::GetInstance()->CreateObject<Charmander>();
	pokeA->transform->position = { -2,0,0 };
	pokeA->SetDir(Vector3(1, 0, 0));
	pokeA->infoVisible = false;

	pokeB = (Character*)ObjectManager::GetInstance()->CreateObject<Squirtle>();
	pokeB->transform->position = { 0,0,2 };
	pokeB->SetDir(Vector3(0, 0, -1));
	pokeB->infoVisible = false;

	pokeC = (Character*)ObjectManager::GetInstance()->CreateObject<Bulbasaur>();
	pokeC->transform->position = { 2,0,0 };
	pokeC->SetDir(Vector3(-1, 0, 0));
	pokeC->infoVisible = false;

	Button* btnRotate = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnRotate->text = L"";
	btnRotate->SetTexture(TextureKey::UI_ICON_ARROW_REFRESH);
	btnRotate->transform->position.x = float((dfCLIENT_WIDTH / 2) - (btnRotate->width / 2));
	btnRotate->transform->position.y = 100.f;
	btnRotate->LButtonDown = StartRotateChar;
	btnRotate->LButtonUp = CancelRotateChar;
	btnRotate->Leave = CancelRotateChar;

	Button* btnLeft = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnLeft->text = L"";
	btnLeft->SetTexture(TextureKey::UI_ICON_ARROW_LEFT);
	btnLeft->transform->position.x = float((dfCLIENT_WIDTH / 2) - (btnLeft->width / 2) - 100);
	btnLeft->transform->position.y = 100.f;

	Button* btnRight = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnRight->text = L"";
	btnRight->SetTexture(TextureKey::UI_ICON_ARROW_RIGHT);
	btnRight->transform->position.x = float((dfCLIENT_WIDTH / 2) - (btnRight->width / 2) + 100);
	btnRight->transform->position.y = 100.f;

	selectedPoke = pokeA;

}

void TestMultiScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TestMultiScene::Update()
{
	if (isClickedRotateButton)
	{
		rotationAngle += D3DXToRadian(5.f);
		rotationAngle = fmodf(rotationAngle, D3DXToRadian(360.f));
		selectedPoke->direction.x += cosf(rotationAngle) - sinf(rotationAngle);
		selectedPoke->direction.z += sinf(rotationAngle) + cosf(rotationAngle);
		Vector3::Normalize(&selectedPoke->direction);

	}
}

void TestMultiScene::StartRotateChar()
{
	isClickedRotateButton = true;
}

void TestMultiScene::CancelRotateChar()
{
	isClickedRotateButton = false;
}

void TestMultiScene::ChangeNext()
{
}

void TestMultiScene::ChangePrev()
{
}
