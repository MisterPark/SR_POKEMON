#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Grass_01::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYDAY_U);
	Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);

	Player::GetInstance()->SetRadianY(D3DXToRadian(30));
	playerCharacter->direction = { 1.f,0.f,1.f };

	Player::GetInstance()->SetCharacter(playerCharacter);
	playerCharacter->transform->position.x = 7.f;
	playerCharacter->transform->position.z = 48.f - 35.f;

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->transform->position = { 18.f,0.f,48.f-21.f };


	Set_Stage_Grass_01_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Grass1.bmp", 0.1f);


}

void Stage_Grass_01::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	Player::GetInstance()->SetCharacter(nullptr);
	ObjectManager::DestroyAll();
}

void Stage_Grass_01::Update()
{


	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Grass_02>();
	}
	Stage_Grass_01_Wave();
	
}


void Stage_Grass_01::Set_Stage_Grass_01_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//물
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::GRASS_WATER_ENVIRONMENT);

	//나무
	for (int i = 0; i < 5; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 15.f + 4 * i;
		tree->transform->position.z += 41.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	}
	for (int i = 0; i < 5; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 26.f + 4 * i;
		tree->transform->position.z += 6.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	}
	for (int i = 0; i < 7; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 6.f;
		tree->transform->position.z += 26.f + 2 * i;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	}
	for (int i = 0; i < 6; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 43.f;
		tree->transform->position.z += 10.f + 2 * i;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	}

}

void Stage_Grass_01::Stage_Grass_01_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::METAPOD, 10.f, 0.5f, 7);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
		}
		else if (spawnerCount == 2)
		{
			Spawner* spawner = Spawner::Create(MonsterType::BUTTERFREE, 10.f, 0.5f, 5);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
			triggerOn = false;
		}
		else if (spawnerCount == 3 && triggerOn == false)
		{
			Player::GetInstance()->Evolution();
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = Portal;
			trigerBox->transform->position = { 40.f,0.f,40.f };
			trigerBox->Portal();
			spawnerCount++;
		}
	}
}

void Stage_Grass_01::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Grass_01::Portal()
{
	SceneManager::LoadScene<Stage_Grass_02>();
}
