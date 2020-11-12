#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Water_01::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<Light>();

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYBLUE1_U);

	SoundManager::PlayBGM(L"WaterStage.wav");

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
	trigerBox->AnimChange(TextureKey::PROPERTY_WATER, TextureKey::PROPERTY_WATER, 10.f, false);

	Set_Stage_Water_01_Map(TextureKey::WATER_MAP, "Texture\\Map\\HeightMap\\Beach.bmp", 9.5f);



}

void Stage_Water_01::OnUnloaded()
{


	ObjectManager::DestroyAll();
}

void Stage_Water_01::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Water_02>();
	}
	Stage_Water_01_Wave();
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

void Stage_Water_01::Stage_Water_01_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::PSYDUCK, 10.f, 0.5f, 10,21);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::POLIWAG, 10.f, 0.5f, 7,23);
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

void Stage_Water_01::CreateSpawner()
{
}

void Stage_Water_01::Portal()
{
	SceneManager::LoadScene<Stage_Water_02>();
}

void Stage_Water_01::TownPortal()
{
	SoundManager::StopSound(SoundChannel::BGM);
	SceneManager::LoadScene<Stage_Town>();
}
