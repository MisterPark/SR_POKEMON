#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Water_Boss::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<Light>();

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYBLUE1_U);
	
	

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(90));
		playerCharacter->direction = { 1.f,0.f,0.f };
		playerCharacter->transform->position.x = 5.f;
		playerCharacter->transform->position.z = 48.f - 44.f;

	}


	Set_Stage_Water_Boss_Map(TextureKey::BROOK_MAP, "Texture\\Map\\HeightMap\\WaterBoss.bmp", 0.f);
	

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	/*trigerBox->OnTriggered = CreateSpawner;*/
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };
}

void Stage_Water_Boss::OnUnloaded()
{
	SoundManager::StopSound(SoundChannel::BGM);
	ObjectManager::DestroyAll();
}

void Stage_Water_Boss::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Fire_01>();
	}
	Stage_Water_Boss_Wave();
}


void Stage_Water_Boss::Set_Stage_Water_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//ÁöÇü
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//¹°
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->WaterTextureChange(TextureKey::WATER_WATER_ENVIRONMENT04, TextureKey::WATER_WATER_ENVIRONMENT04, false);


}

void Stage_Water_Boss::Stage_Water_Boss_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::POLIWRATH, 10.f, 0.5f, 5.33);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::JYNX, 10.f, 0.5f, 5.35);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
		}
		else if (spawnerCount == 2)
		{
			SoundManager::StopSound(SoundChannel::BGM);
			SoundManager::PlayBGM(L"Boss.wav");

			Spawner* spawner = Spawner::Create(MonsterType::SUICUNE, 10.f, 0.5f, 1.40);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
			triggerOn = false;
		}
		else if (spawnerCount == 3 && triggerOn == false)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = TownPortal;
			trigerBox->transform->position = { 8.f,0.f,8.f };
			trigerBox->Portal();

			spawnerCount++;
		}
	}
}

void Stage_Water_Boss::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::SCYTHER, 10.f, 0.5f, 1);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Water_Boss::TownPortal()
{
	SceneManager::LoadScene<Stage_Town>();
}
