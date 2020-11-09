#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Fire_01::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYFIRE1_U);


	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(90));
		playerCharacter->direction = { 1.f,0.f,0.f };
		playerCharacter->transform->position.x = 1.f;
		playerCharacter->transform->position.z = 48.f - 24.f;
		Camera::GetInstance()->SetTarget(playerCharacter);
	}

	waterHeight = 10.15f;

	Set_Stage_Fire_01_Map(TextureKey::VOLCANO_MAP, "Texture\\Map\\HeightMap\\Fire1.bmp", waterHeight);

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	/*trigerBox->OnTriggered = CreateSpawner;*/
	trigerBox->transform->position = { 24.f,0.f,48.f - 22.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_FIRE, TextureKey::PROPERTY_FIRE, 10.f, false);

}

void Stage_Fire_01::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	ObjectManager::DestroyAll();
}

void Stage_Fire_01::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Fire_02>();
	}
	Stage_Fire_01_Wave();
	soHot(waterHeight);
}


void Stage_Fire_01::Set_Stage_Fire_01_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//ÁöÇü
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//¹°
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->Lava();

}

void Stage_Fire_01::Stage_Fire_01_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::GROWLITHE, 10.f, 0.5f, 10);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::PONYTA, 10.f, 0.5f, 7);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
		}
		else if (spawnerCount == 2)
		{
			Spawner* spawner = Spawner::Create(MonsterType::SLUGMA, 10.f, 0.5f, 5);
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
			trigerBox->Portal();

			trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = TownPortal;
			trigerBox->transform->position = { 8.f,0.f,8.f };
			trigerBox->Portal();

			spawnerCount++;
		}
	}
}

void Stage_Fire_01::CreateSpawner()
{
}

void Stage_Fire_01::Portal()
{
	SceneManager::LoadScene<Stage_Fire_02>();
}

void Stage_Fire_01::TownPortal()
{
	SceneManager::LoadScene<Stage_Town>();
}

void Stage_Fire_01::soHot(float _waterheight)
{
	if (Player::GetInstance()->GetCharacter()->transform->position.y <= _waterheight)
	{
		Player::GetInstance()->GetCharacter()->MinusHp(dfSOHOT_DAMAGE);
	}
}
