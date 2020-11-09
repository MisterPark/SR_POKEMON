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

	Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);

	Player::GetInstance()->SetRadianY(D3DXToRadian(90));
	playerCharacter->direction = { 1.f,0.f,0.f };

	Player::GetInstance()->SetCharacter(playerCharacter);
	playerCharacter->transform->position.x = 1.f;
	playerCharacter->transform->position.z = 48.f - 24.f;



	Set_Stage_Fire_01_Map(TextureKey::VOLCANO_MAP, "Texture\\Map\\HeightMap\\Fire1.bmp", 10.15f);



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
		SceneManager::LoadScene<Stage_Fire_Boss>();
	}
}


void Stage_Fire_01::Set_Stage_Fire_01_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//물
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->Lava();
	//나무

	//for (int i = 0; i < 8; i++)
	//{
	//	GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	//	tree->transform->position.x += 3.f + 2 * i;
	//	tree->transform->position.z += 45.f;
	//	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::PALMTREE02);
	//}
	//for (int i = 0; i < 10; i++)
	//{
	//	GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	//	tree->transform->position.x += 3.f + 2 * i;
	//	tree->transform->position.z += 2.f;
	//	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::PALMTREE02);

	//}
	//for (int i = 0; i < 9; i++)
	//{
	//	GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	//	tree->transform->position.x += 46.f;
	//	tree->transform->position.z += 20.f + 2 * i;
	//	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::PALMTREE03);
	//}
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
