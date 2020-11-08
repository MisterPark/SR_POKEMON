#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Fire_Boss::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYNIGHT_U);

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	Player::GetInstance()->SetRadianY(D3DXToRadian(45));
	playerCharacter->direction = { 1.f,0.f,1.f };
	playerCharacter->transform->position.x = 25.f;
	playerCharacter->transform->position.z = 48.f - 25.f;
	Camera::GetInstance()->SetTarget(playerCharacter);

	Set_Stage_Fire_Boss_Map(TextureKey::VOLCANO_MAP, "Texture\\Map\\HeightMap\\FireBoss.bmp", 0.1f);


	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };

}

void Stage_Fire_Boss::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	ObjectManager::DestroyAll();
}

void Stage_Fire_Boss::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<TestScene>();
	}
	Stage_Fire_Boss_Wave();
}


void Stage_Fire_Boss::Set_Stage_Fire_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//ÁöÇü
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//¹°
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;


}

void Stage_Fire_Boss::Stage_Fire_Boss_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::GROUDON, 10.f, 0.5f, 1);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);

		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = Portal;
			trigerBox->transform->position = { 40.f,0.f,40.f };
			trigerBox->Portal();
			spawnerCount++;

		}

	}
}

void Stage_Fire_Boss::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::GROUDON, 10.f, 0.5f, 1);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Fire_Boss::Portal()
{
	SceneManager::LoadScene<Stage_Water_01>();
}
