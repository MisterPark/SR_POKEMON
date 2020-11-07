#include "stdafx.h"
#include "TestMultiScene.h"
#include "SkyBox.h"
#include "Charmander.h"
#include "Button.h"

bool isClickedRotateButton = false;

float rotationAngle = 0.f;

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

	Button* btnRotate = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnRotate->text = L"";
	btnRotate->SetTexture(TextureKey::UI_ICON_ARROW_REFRESH);
	btnRotate->transform->position.x = (dfCLIENT_WIDTH / 2) - (btnRotate->width / 2);
	btnRotate->transform->position.y = 600;
	btnRotate->LButtonDown = StartRotateChar;
	btnRotate->LButtonUp = CancelRotateChar;
	btnRotate->Leave = CancelRotateChar;

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
