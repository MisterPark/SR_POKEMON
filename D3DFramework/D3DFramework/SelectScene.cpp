#include "stdafx.h"
#include "SelectScene.h"
#include "SkyBox.h"
#include "AllCharacters.h"
#include "Button.h"
#include "AllStage.h"

Character* SelectScene::selectedPoke = nullptr;
Pokemon SelectScene::selectedIndex = Pokemon::Charmander;
bool SelectScene::isClickedRotateButton = false;
float SelectScene::rotationAngle = 0.f;

void SelectScene::OnLoaded()
{
	SelectScene::selectedPoke = nullptr;
	SelectScene::selectedIndex = Pokemon::Charmander;
	SelectScene::isClickedRotateButton = false;
	SelectScene::rotationAngle = 0.f;

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYBLUE1_U);
	Camera::GetInstance()->SetPosition(Vector3(0, 0, 0));
	Camera::GetInstance()->transform->look = Vector3::LEFT;

	//Network::Connect();

	pokeA = (Character*)Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(pokeA);
	pokeA->transform->position = { -2,0,0 };
	pokeA->SetDir(Vector3(1, 0, 0));
	pokeA->infoVisible = false;
	pokeA->team = Team::NEUTRAL;

	pokeB = (Character*)Squirtle::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(pokeB);
	pokeB->transform->position = { 0,0,2 };
	pokeB->SetDir(Vector3(0, 0, -1));
	pokeB->infoVisible = false;
	pokeB->team = Team::NEUTRAL;

	pokeC = (Character*)Bulbasaur::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(pokeC);
	pokeC->transform->position = { 2,0,0 };
	pokeC->SetDir(Vector3(-1, 0, 0));
	pokeC->infoVisible = false;
	pokeC->team = Team::NEUTRAL;

	Button* btnRotate = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnRotate->text = L"";
	btnRotate->SetTexture(TextureKey::UI_ICON_ARROW_REFRESH);
	btnRotate->transform->position.x = (dfCLIENT_WIDTH / 2) - (btnRotate->width / 2);
	btnRotate->transform->position.y = 100;
	btnRotate->LButtonDown = StartRotateChar;
	btnRotate->LButtonUp = CancelRotateChar;
	btnRotate->Leave = CancelRotateChar;

	Button* btnLeft = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnLeft->text = L"";
	btnLeft->SetTexture(TextureKey::UI_ICON_ARROW_LEFT);
	btnLeft->transform->position.x = (dfCLIENT_WIDTH / 2) - (btnLeft->width / 2) - 100;
	btnLeft->transform->position.y = 100;
	btnLeft->Click = ChangePrev;

	Button* btnRight = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btnRight->text = L"";
	btnRight->SetTexture(TextureKey::UI_ICON_ARROW_RIGHT);
	btnRight->transform->position.x = (dfCLIENT_WIDTH / 2) - (btnRight->width / 2) + 100;
	btnRight->transform->position.y = 100;
	btnRight->Click = ChangeNext;

	Button* btn = (Button*)ObjectManager::GetInstance()->CreateObject<Button>();
	btn->text = L"¼±ÅÃ";
	btn->SetSize(250, 40);
	btn->transform->position.x = (dfCLIENT_WIDTH / 2) - (btn->width / 2);
	btn->transform->position.y = 600;

	btn->Click = SelectCharacter;

	selectedPoke = pokeA;
}

void SelectScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void SelectScene::Update()
{
	if (selectedIndex == Pokemon::Charmander)
	{
		selectedPoke = pokeA;
	}
	else if (selectedIndex == Pokemon::Squirtle)
	{
		selectedPoke = pokeB;
	}
	else if (selectedIndex == Pokemon::Bulbasaur)
	{
		selectedPoke = pokeC;
	}
	
	if (isClickedRotateButton)
	{
		rotationAngle += D3DXToRadian(5.f);
		rotationAngle = fmodf(rotationAngle, D3DXToRadian(360.f));
		selectedPoke->direction.x += cosf(rotationAngle) - sinf(rotationAngle);
		selectedPoke->direction.z += sinf(rotationAngle) + cosf(rotationAngle);
		Vector3::Normalize(&selectedPoke->direction);

	}
}

void SelectScene::StartRotateChar()
{
	isClickedRotateButton = true;
}

void SelectScene::CancelRotateChar()
{
	isClickedRotateButton = false;
}

void SelectScene::ChangeNext()
{
	if (selectedIndex == Pokemon::Charmander)
	{
		selectedIndex = Pokemon::Squirtle;
		Camera::GetInstance()->transform->look = Vector3::FORWARD;

	}
	else if (selectedIndex == Pokemon::Squirtle)
	{
		selectedIndex = Pokemon::Bulbasaur;
		Camera::GetInstance()->transform->look = Vector3::RIGHT;
	}
	else if (selectedIndex == Pokemon::Bulbasaur)
	{
		selectedIndex = Pokemon::Charmander;
		Camera::GetInstance()->transform->look = Vector3::LEFT;
	}
}

void SelectScene::ChangePrev()
{
	if (selectedIndex == Pokemon::Charmander)
	{
		selectedIndex = Pokemon::Bulbasaur;
		Camera::GetInstance()->transform->look = Vector3::RIGHT;
	}
	else if (selectedIndex == Pokemon::Squirtle)
	{
		selectedIndex = Pokemon::Charmander;
		Camera::GetInstance()->transform->look = Vector3::LEFT;
	}
	else if (selectedIndex == Pokemon::Bulbasaur)
	{
		selectedIndex = Pokemon::Squirtle;
		Camera::GetInstance()->transform->look = Vector3::FORWARD;
	}
}

void SelectScene::SelectCharacter()
{
	Player::GetInstance()->Initialize();
	Player::GetInstance()->ChangeNextPokemon(selectedPoke->type, selectedPoke->number);
	Player::GetInstance()->PermanentMetamorphosis();

	selectedPoke->Die();

	SceneManager::LoadScene<Stage_Tutorial>();
}
