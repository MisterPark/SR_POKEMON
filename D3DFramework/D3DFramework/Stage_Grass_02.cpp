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
		Camera::GetInstance()->SetTarget(playerCharacter);
	}
	

	//Vileplume* monsterCharacter4 = Vileplume::Create(Vector3(35.f, 0.f, 8.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter4->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter4->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter4->monsterAI->SetType(MonsterType::VILEPLUME);
	//ObjectManager::AddObject(monsterCharacter4);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter4);

	//Scyther* monsterCharacter5 = Scyther::Create(Vector3(42.f, 0.f, 42.f), Vector3(1.f, 1.f, 1.f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter5->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter5->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter5->monsterAI->SetType(MonsterType::SCYTHER);
	//ObjectManager::AddObject(monsterCharacter5);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter5);



	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	/*trigerBox->OnTriggered = CreateSpawner;*/
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };


	Set_Stage_Grass_02_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Grass2.bmp", 0.1f);


}

void Stage_Grass_02::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
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
	//����
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//��
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::GRASS_WATER_ENVIRONMENT);

	//����
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
	////��ȣ
	//for (float i = 0; i < 3; i+=0.7)
	//{
	//	for (float j = 0; j < 3; j+=0.7)
	//	{
	//		GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
	//		coral->transform->position.x = 16.f + i;
	//		coral->transform->position.z = 48.f - 21.f + j;
	//		dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::BLUECORAL01);
	//	}
	//}
	//for (float i = 0; i < 3; i+=0.7)
	//{
	//	for (float j = 0; j < 3; j+=0.7)
	//	{
	//		GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
	//		coral->transform->position.x = 20.f + i;
	//		coral->transform->position.z = 48.f - 32.f + j;
	//		dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::WHITECORAL02);
	//	}
	//}
	//for (float i = 0; i < 3; i+=0.7)
	//{
	//	for (float j = 0; j < 3; j+=0.7)
	//	{
	//		GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
	//		coral->transform->position.x = 28.f + i;
	//		coral->transform->position.z = 48.f - 25.f + j;
	//		dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::REDCORAL01);
	//	}
	//}
	//for (float i = 0; i < 3; i+=0.7)
	//{
	//	for (float j = 0; j < 3; j+=0.7)
	//	{
	//		GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
	//		coral->transform->position.x = 27.f + i;
	//		coral->transform->position.z = 48.f - 16.f + j;
	//		dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::PURPLECORAL01);
	//	}
	//}
	//for (float i = 0; i < 3; i+=0.7)
	//{
	//	for (float j = 0; j < 3; j+=0.7)
	//	{
	//		GameObject* coral = ObjectManager::GetInstance()->CreateObject<Coral>();
	//		coral->transform->position.x = 32.f + i;
	//		coral->transform->position.z = 48.f - 29.f + j;
	//		dynamic_cast<Coral*>(coral)->setCoralSprite(TextureKey::YELLOWCORAL01);
	//	}
	//}

}

void Stage_Grass_02::Stage_Grass_02_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		Spawner* spawner = Spawner::Create(MonsterType::ODDISH, 10.f, 0.5f, 10);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			Spawner* spawner = Spawner::Create(MonsterType::GLOOM, 10.f, 0.5f, 7);
			spawner->transform->position = { 24.f,0.f,24.f };
			ObjectManager::AddObject(spawner);
			spawnerCount++;
		}
		else if (spawnerCount == 2)
		{
			Spawner* spawner = Spawner::Create(MonsterType::VILEPLUME, 10.f, 0.5f, 5);
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
