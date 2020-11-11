#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Grass_Boss::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<Light>();

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYNIGHT_U);

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(45));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 1.f;
		playerCharacter->transform->position.z = 48.f - 47.f;

	}


	Set_Stage_Grass_Boss_Map(TextureKey::GRASS_MAP2, "Texture\\Map\\HeightMap\\Lake3.bmp", 8.5f);


	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_GRASS, TextureKey::PROPERTY_GRASS, 10.f, false);
}

void Stage_Grass_Boss::OnUnloaded()
{
	SoundManager::StopSound(SoundChannel::BGM);
	ObjectManager::DestroyAll();
}

void Stage_Grass_Boss::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Water_01>();
	}
	Stage_Grass_Boss_Wave();
}


void Stage_Grass_Boss::Set_Stage_Grass_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//¡ˆ«¸
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//π∞
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;

	for (int i = 0; i < 10; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 19.f + 2 * i;
		tree->transform->position.z += 8.5f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	}
	//≥Ù¿Ã∏  ±‚¡ÿ øﬁ¬ 
	for (int i = 0; i < 16; i++)
	{
		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x += 7.f;
		tree->transform->position.z += 14.f + 2 * i;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	}

	GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	tree->transform->position.x = 32.f;
	tree->transform->position.z += 48.f - 2.f;
	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	tree->transform->position.x = 35.f;
	tree->transform->position.z += 48.f - 7.f;
	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	tree->transform->position.x = 38.f;
	tree->transform->position.z += 48.f - 12.f;
	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);
	tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	tree->transform->position.x = 43.f;
	tree->transform->position.z += 48.f - 15.f;
	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE06);
	tree = ObjectManager::GetInstance()->CreateObject<Tree>();
	tree->transform->position.x = 46.f;
	tree->transform->position.z += 48.f - 17.f;
	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE05);

}

void Stage_Grass_Boss::Stage_Grass_Boss_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::ODDISH, 10.f, 0.5f, 5);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);

		spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 5);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);

		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::GLOOM, 10.f, 0.5f, 4);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawner = Spawner::Create(MonsterType::METAPOD, 10.f, 0.5f, 4);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);

			spawnerCount++;

		}
		else if (spawnerCount == 2)
		{

			Spawner* spawner = Spawner::Create(MonsterType::VILEPLUME, 10.f, 0.5f, 3);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawner = Spawner::Create(MonsterType::BUTTERFREE, 10.f, 0.5f, 3);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);

			spawnerCount++;
		}
		else if (spawnerCount == 3)
		{
			SoundManager::StopSound(SoundChannel::BGM);
			SoundManager::PlayBGM(L"Boss.wav");
			SoundManager::SetVolume(SoundChannel::BGM, 0.1f);

			Spawner* spawner = Spawner::Create(MonsterType::SCYTHER, 10.f, 0.5f, 1);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);


			spawnerCount++;
			triggerOn = false;
		}

		else if (spawnerCount == 4 && triggerOn == false)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = TownPortal;
			trigerBox->transform->position = { 40.f,0.f,40.f };
			trigerBox->Portal();
			spawnerCount++;
		}
	}
}

void Stage_Grass_Boss::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::SCYTHER, 10.f, 0.5f, 1, 15);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}


void Stage_Grass_Boss::TownPortal()
{
	SceneManager::LoadScene<Stage_Town>();
}
