#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Grass_02::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYDAY_U);

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(60));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 7.f;
		playerCharacter->transform->position.z = 48.f - 24.f;

	}


	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_GRASS, TextureKey::PROPERTY_GRASS, 10.f, false);

	Set_Stage_Grass_02_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Grass2.bmp", 0.1f);


}

void Stage_Grass_02::OnUnloaded()
{

	ObjectManager::DestroyAll();
}

void Stage_Grass_02::Update()
{


	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Grass_Boss>();
	}
	Stage_Grass_02_Wave();

}


void Stage_Grass_02::Set_Stage_Grass_02_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
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
	for (int i = 0; i < 4; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 19.f + 3 * i;
		tree->transform->position.z += 48.f-12.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	}
	for (int i = 0; i < 5; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 20.f + 3 * i;
		tree->transform->position.z += 48.f-30.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	}
	for (int i = 0; i < 7; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 16.f;
		tree->transform->position.z += 48.f-27.f + 2 * i;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	}
	for (int i = 0; i < 6; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 32.f;
		tree->transform->position.z += 48.f - 25.f + 2 * i;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	}


}

void Stage_Grass_02::Stage_Grass_02_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::ODDISH, 10.f, 0.5f, 10,7);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::GLOOM, 10.f, 0.5f, 7,8);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
		}
		else if (spawnerCount == 2)
		{
			Spawner* spawner = Spawner::Create(MonsterType::VILEPLUME, 10.f, 0.5f, 5,10);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
			triggerOn = false;
		}
		else if (spawnerCount == 3 && triggerOn == false)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = Portal;
			trigerBox->transform->position = { 40.f,0.f,40.f };
			trigerBox->AnimChange(TextureKey::PROPERTY_GRASS, TextureKey::PROPERTY_GRASS, 10.f, false);

			trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = TownPortal;
			trigerBox->transform->position = { 8.f,0.f,8.f };
			trigerBox->Portal();
			spawnerCount++;
		}
	}
}

void Stage_Grass_02::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Grass_02::Portal()
{
	SceneManager::LoadScene<Stage_Grass_Boss>();
}

void Stage_Grass_02::TownPortal()
{
	SceneManager::LoadScene<Stage_Town>();
}
