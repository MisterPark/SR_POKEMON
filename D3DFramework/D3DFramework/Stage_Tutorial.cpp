#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"
#include "Item_Tomato.h"

void Stage_Tutorial::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYDAY_U);
	Cursor::Hide();

	/*CollisionManager* col = CollisionManager::GetInstance();*/

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(30));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 24.f;
		playerCharacter->transform->position.z = 48.f - 24.f;

	}

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->transform->position = { 24.f,0.f,30.f };
	trigerBox->AnimChange(TextureKey::POP_01, TextureKey::POP_34,0.05f, true);

	Set_Stage_Tutorial_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Town.bmp", -0.1f);

}

void Stage_Tutorial::OnUnloaded()
{

	ObjectManager::DestroyAll();
}

void Stage_Tutorial::Update()
{


	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Town>();
	}
	Stage_Tutorial_Wave();
	
}


void Stage_Tutorial::Set_Stage_Tutorial_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
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

void Stage_Tutorial::Stage_Tutorial_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
		trigerBox->transform->position = { 24.f,0.f,20.f };
		trigerBox->AnimChange(TextureKey::PROPERTY_GRASS, TextureKey::PROPERTY_GRASS, 10.f, false);
		spawnerCount++;
		
		
	}
	else if (nullptr == isTriger&&spawnerCount == 1)
	{
		Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 3);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = false;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 2)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = Portal;
			trigerBox->transform->position = { 24.f,0.f,10.f };
			trigerBox->Portal();

			spawnerCount++;

		}

	}
}


void Stage_Tutorial::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Tutorial::Portal()
{
	SceneManager::LoadScene<Stage_Town>();
}
