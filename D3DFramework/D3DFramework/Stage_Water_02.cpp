#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Water_02::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYBEACH2_U);


	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(30));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 7.f;
		playerCharacter->transform->position.z = 48.f - 35.f;
		Camera::GetInstance()->SetTarget(playerCharacter);
	}


	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	/*trigerBox->OnTriggered = CreateSpawner;*/
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_WATER, TextureKey::PROPERTY_WATER, 10.f, false);

	Set_Stage_Water_02_Map(TextureKey::BROOK_MAP, "Texture\\Map\\HeightMap\\Lake.bmp", 9.9f);


}

void Stage_Water_02::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);

	ObjectManager::DestroyAll();
}

void Stage_Water_02::Update()
{


	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Water_Boss>();
	}
	Stage_Water_02_Wave();

}


void Stage_Water_02::Set_Stage_Water_02_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//ÁöÇü
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//¹°
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::GRASS_WATER_ENVIRONMENT);


	for (float i = 0; i < 3; i += 0.7)
	{
		for (float j = 0; j < 3; j += 0.7)
		{
			GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
			coral->transform->position.x = 16.f + i;
			coral->transform->position.z = 48.f - 21.f + j;
			dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::BLUECORAL01);
		}
	}
	for (float i = 0; i < 3; i += 0.7)
	{
		for (float j = 0; j < 3; j += 0.7)
		{
			GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
			coral->transform->position.x = 20.f + i;
			coral->transform->position.z = 48.f - 32.f + j;
			dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::WHITECORAL02);
		}
	}
	for (float i = 0; i < 3; i += 0.7)
	{
		for (float j = 0; j < 3; j += 0.7)
		{
			GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
			coral->transform->position.x = 28.f + i;
			coral->transform->position.z = 48.f - 25.f + j;
			dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::REDCORAL01);
		}
	}
	for (float i = 0; i < 3; i += 0.7)
	{
		for (float j = 0; j < 3; j += 0.7)
		{
			GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
			coral->transform->position.x = 27.f + i;
			coral->transform->position.z = 48.f - 16.f + j;
			dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::PURPLECORAL01);
		}
	}
	for (float i = 0; i < 3; i += 0.7)
	{
		for (float j = 0; j < 3; j += 0.7)
		{
			GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
			coral->transform->position.x = 32.f + i;
			coral->transform->position.z = 48.f - 29.f + j;
			dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::YELLOWCORAL01);
		}
	}

}

void Stage_Water_02::Stage_Water_02_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::GOLDUCK, 10.f, 0.5f, 10);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::POLIWHIRL, 10.f, 0.5f, 7);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
			triggerOn = false;
		}

		else if (spawnerCount == 2 && triggerOn == false)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = Portal;
			trigerBox->transform->position = { 40.f,0.f,40.f };
			trigerBox->AnimChange(TextureKey::PROPERTY_WATER, TextureKey::PROPERTY_WATER, 10.f, false);

			trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = TownPortal;
			trigerBox->transform->position = { 8.f,0.f,8.f };
			trigerBox->Portal();

			spawnerCount++;
		}
	}
}

void Stage_Water_02::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Water_02::Portal()
{
	SceneManager::LoadScene<Stage_Water_Boss>();
}

void Stage_Water_02::TownPortal()
{
	SceneManager::LoadScene<Stage_Town>();
}
