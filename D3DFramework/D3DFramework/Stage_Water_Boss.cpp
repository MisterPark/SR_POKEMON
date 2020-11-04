#include "stdafx.h"
#include "Stage_Water_Boss.h"
#include "SkyBox.h"
#include "Environment.h"
#include "TitleScene.h"


#include "Bulbasaur.h"
#include "Ivysaur.h"
#include "Venusaur.h"

#include "Charmander.h"

#include "Caterpie.h"
#include "Metapod.h"
#include "Butterfree.h"
#include "Oddish.h"
#include "Vileplume.h"
#include "Scyther.h"
#include "Celebi.h"

#include "Water.h"
#include "Tree.h"

#include "Stage_Fire_01.h"
#include "TriggerBox.h"

void Stage_Water_Boss::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SPACE1_U);
	Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);

	Player::GetInstance()->SetRadianY(D3DXToRadian(90));
	playerCharacter->direction = { 1.f,0.f,0.f };

	Player::GetInstance()->SetCharacter(playerCharacter);
	playerCharacter->transform->position.x = 5.f;
	playerCharacter->transform->position.z = 48.f - 44.f;
	Set_Stage_Water_Boss_Map(TextureKey::BROOK_MAP, "Texture\\Map\\HeightMap\\Brook.bmp", 0.f);
	
	float size = 1.f;
	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->OnTriggered = Create_Monster_A_Spawner;
	trigerBox->transform->position = { 17.f,0.f,48.f-4.f };
	trigerBox->transform->scale += {size, size, size};
	trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->OnTriggered = Create_Monster_B_Spawner;
	trigerBox->transform->position = { 44.f,0.f,48.f - 18.f };
	trigerBox->transform->scale += {size, size, size};
	trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->OnTriggered = Create_Monster_C_Spawner;
	trigerBox->transform->position = { 43.f,0.f,48.f - 32.f };
	trigerBox->transform->scale += {size, size, size};
}

void Stage_Water_Boss::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	Player::GetInstance()->SetCharacter(nullptr);
	ObjectManager::DestroyAll();
}

void Stage_Water_Boss::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Fire_01>();
	}
}


void Stage_Water_Boss::Set_Stage_Water_Boss_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//물
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->Normal();
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

void Stage_Water_Boss::Create_Monster_A_Spawner()
{
	Spawner* poliwagSpawner = Spawner::Create(MonsterType::POLIWAG, 7.f, 0.5f, 10);
	poliwagSpawner->transform->position = { 6.f,0.f,48.f-13.f };
	ObjectManager::AddObject(poliwagSpawner);

}

void Stage_Water_Boss::Create_Monster_B_Spawner()
{
	Spawner* poliwagSpawner = Spawner::Create(MonsterType::POLIWRATH, 10.f, 0.5f, 10);
	poliwagSpawner->transform->position = { 41.f,0.f,48.f - 8.f };
	ObjectManager::AddObject(poliwagSpawner);
}

void Stage_Water_Boss::Create_Monster_C_Spawner()
{
	Spawner* poliwagSpawner = Spawner::Create(MonsterType::GOLDUCK, 6.f, 0.5f, 10);
	poliwagSpawner->transform->position = { 36.f,0.f,48.f - 42.f };
	ObjectManager::AddObject(poliwagSpawner);
}
