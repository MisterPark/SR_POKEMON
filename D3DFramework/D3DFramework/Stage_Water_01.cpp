#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Water_01::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYBEACH1_U);
	Suicune* playerCharacter = Suicune::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, 0.f, 1.f));
	playerCharacter->offsetY = 0.35f;
	//Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);

	Player::GetInstance()->SetRadianY(D3DXToRadian(90));
	playerCharacter->direction = { 1.f,0.f,0.f };

	Player::GetInstance()->SetCharacter(playerCharacter);
	playerCharacter->transform->position.x = 1.f;
	playerCharacter->transform->position.z = 48.f - 24.f;



	Set_Stage_Water_01_Map(TextureKey::WATER_MAP, "Texture\\Map\\HeightMap\\Beach.bmp", 9.5f);

	



}

void Stage_Water_01::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	Player::GetInstance()->SetCharacter(nullptr);
	ObjectManager::DestroyAll();
}

void Stage_Water_01::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Water_Boss>();
	}
}


void Stage_Water_01::Set_Stage_Water_01_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//물
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->Beach();
	//나무

	for (int i = 0; i < 8; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 3.f + 2 * i;
		tree->transform->position.z += 45.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::PALMTREE02);
	}
	for (int i = 0; i < 10; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 3.f + 2 * i;
		tree->transform->position.z += 2.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::PALMTREE02);

	}
	for (int i = 0; i < 9; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 46.f;
		tree->transform->position.z += 20.f + 2 * i;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::PALMTREE03);
	}
}
