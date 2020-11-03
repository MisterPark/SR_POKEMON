#include "stdafx.h"
#include "TestScene.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "SkyBox.h"
#include "CubeMan.h"
#include "Environment.h"
#include "TitleScene.h"

#include "Charmander.h"

#include "Bulbasaur.h"
#include "Ivysaur.h"
#include "Venusaur.h"

#include "Caterpie.h"
#include "Metapod.h"
#include "Butterfree.h"
#include "Oddish.h"
#include "Vileplume.h"
#include "Scyther.h"

#include "Psyduck.h"
#include "Golduck.h"
#include "Poliwag.h"
#include "Poliwrath.h"
#include "Jynx.h"
#include "Suicune.h"

#include "MonsterAI.h"

#include "Water.h"
#include "Tree.h"
#include "Stage_Grass_01.h"

#include "Spawner.h"
void TestScene::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKY_U);
	Camera::GetInstance()->SetPosition(Vector3(24.f, 0,48.f - 24.f));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 0);

	// TestUI
	
	
	Scyther* playerCharacter = Scyther::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, 0.f, 1.f));
	/*Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, 0.f, 1.f));*/
	ObjectManager::AddObject(playerCharacter);

	//7시
	Player::GetInstance()->SetRadianY(D3DXToRadian(180));
	playerCharacter->direction = { -1.f,0.f,-1.f };

	Player::GetInstance()->SetCharacter(playerCharacter);
	playerCharacter->transform->position.x = 24.f;
	playerCharacter->transform->position.z = 48.f - 24.f;



	//SetTestSceneMap(TextureKey::WATER_MAP, "Texture\\Map\\HeightMap\\Beach.bmp", 3.5f);
	/*SetTestSceneMap(TextureKey::BROOK_MAP, "Texture\\Map\\HeightMap\\Brook.bmp", 0.f);*/
	SetTestSceneMap(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Normal.bmp",-0.1f);
	//SetTestSceneMap(TextureKey::BROOK_MAP, "Texture\\Map\\HeightMap\\Brook.bmp", 4.05f);
	//SetTestSceneMap(TextureKey::GRASS_MAP2, "Texture\\Map\\HeightMap\\Lake3.bmp",3.5f);

	Spawner* poliwagSpawner = Spawner::Create(MonsterType::VILEPLUME, 10.f, 0.5f);
	poliwagSpawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(poliwagSpawner);

	//Poliwag* monsterCharacter = Poliwag::Create(Vector3(20.f, 0.f, 20.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter->monsterAI->SetType(MonsterType::POLIWAG);
	//ObjectManager::AddObject(monsterCharacter);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);



	//Butterfree* monsterCharacter = Butterfree::Create(Vector3(5.f, 0.f, 7.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter->monsterAI->SetType(MonsterType::BUTTERFREE);
	//ObjectManager::AddObject(monsterCharacter);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);

	//Oddish* monsterCharacter2 = Oddish::Create(Vector3(15.f, 0.f, 9.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter2->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter2->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter2->monsterAI->SetType(MonsterType::ODDISH);
	//ObjectManager::AddObject(monsterCharacter2);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter2);

	//Metapod* monsterCharacter3 = Metapod::Create(Vector3(25.f, 0.f, 6.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter3->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter3->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter3->monsterAI->SetType(MonsterType::METAPOD);
	//ObjectManager::AddObject(monsterCharacter3);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter3);

	//Caterpie* monsterCharacter6 = Caterpie::Create(Vector3(42.f, 0.f, 26.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter6->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter6->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter6->monsterAI->SetType(MonsterType::CATERPIE);
	//ObjectManager::AddObject(monsterCharacter6);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter6);

	//Butterfree* monsterCharacter7 = Butterfree::Create(Vector3(35.f, 0.f, 27.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter7->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter7->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter7->monsterAI->SetType(MonsterType::BUTTERFREE);
	//ObjectManager::AddObject(monsterCharacter7);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter7);

	//Oddish* monsterCharacter8 = Oddish::Create(Vector3(25.f, 0.f, 15.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter8->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter8->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter8->monsterAI->SetType(MonsterType::ODDISH);
	//ObjectManager::AddObject(monsterCharacter8);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter8);

	//Metapod* monsterCharacter9 = Metapod::Create(Vector3(35.f, 0.f, 25.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter9->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter9->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter9->monsterAI->SetType(MonsterType::METAPOD);
	//ObjectManager::AddObject(monsterCharacter9);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter9);

	//Vileplume* monsterCharacter10 = Vileplume::Create(Vector3(25.f, 0.f, 35.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter10->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter10->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter10->monsterAI->SetType(MonsterType::VILEPLUME);
	//ObjectManager::AddObject(monsterCharacter10);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter10);

	//Caterpie* monsterCharacter11 = Caterpie::Create(Vector3(35.f, 0.f, 42.f), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
	//monsterCharacter11->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter11->AddComponent<MonsterAI>(L"MonsterAI"));
	//monsterCharacter11->monsterAI->SetType(MonsterType::CATERPIE);
	//ObjectManager::AddObject(monsterCharacter11);
	//CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter11);
	
	/*GameObject* Obj = ObjectManager::GetInstance()->CreateObject<Poliwrath>();
	Obj->transform->position.x += 7;
	Obj->transform->position.z += 7;
	Obj = ObjectManager::GetInstance()->CreateObject<Oddish>();
	Obj->transform->position.x += 5;
	Obj->transform->position.z += 5;
	Obj = ObjectManager::GetInstance()->CreateObject<Poliwrath>();
	Obj->transform->position.x += 3;
	Obj->transform->position.z += 3;*/

}

void TestScene::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	Player::GetInstance()->SetCharacter(nullptr);
	ObjectManager::DestroyAll();
}

void TestScene::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Grass_01>();
	}
}


void TestScene::SetTestSceneMap(TextureKey _key, const std::string& _filePath,float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();

	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);
	//Tip) 높이맵의 높이는 RGB/25로 설정되어있습니다. 따라서 y축을 5로 설정할 지형을 만들고 싶다면
	//색상값을 125로 준 채로 드로잉하면 됩니다.





	if (_key == TextureKey::GRASS_MAP)
	{
		//물
		GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
		water->transform->position.y = _waterHeight;
		dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::GRASS_WATER_ENVIRONMENT);
	
		//나무
		for (int i = 0; i < 10; i++)
		{
			GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
			tree->transform->position.x += 15.f + 2 * i;
			tree->transform->position.z += 41.f;
			dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE04);
		}
		for (int i = 0; i < 10; i++)
		{
			GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
			tree->transform->position.x += 15.f + 2 * i;
			tree->transform->position.z += 6.f;
		}
		for (int i = 0; i < 16; i++)
		{
			GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
			tree->transform->position.x += 6.f;
			tree->transform->position.z += 8.f + 2 * i;
			dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE04);
		}
		for (int i = 0; i < 6; i++)
		{
			GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
			tree->transform->position.x += 45.f;
			tree->transform->position.z += 16.f + 2 * i;
			dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE03);
		}
	}
	if (_key == TextureKey::GRASS_MAP2)
	{
		//물
		GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
		water->transform->position.y = _waterHeight;
		dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::GRASS_WATER_ENVIRONMENT);
		//나무
		////높이맵 기준 위쪽
		//for (int i = 0; i < 10; i++)
		//{
		//	GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		//	tree->transform->position.x += 15.f + 2 * i;
		//	tree->transform->position.z += 41.f;
		//	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE04);
		//}
		//높이맵 기준 아래쪽
		for (int i = 0; i < 10; i++)
		{
			GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
			tree->transform->position.x += 19.f + 2 * i;
			tree->transform->position.z += 8.5f;
		}
		//높이맵 기준 왼쪽
		for (int i = 0; i < 16; i++)
		{
			GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
			tree->transform->position.x += 7.f;
			tree->transform->position.z += 14.f + 2 * i;
			
			dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE04);
		}

		GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x = 32.f;
		tree->transform->position.z += 48.f -2.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE04);
		tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x = 35.f;
		tree->transform->position.z += 48.f - 7.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE03);
		tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x = 38.f;
		tree->transform->position.z += 48.f - 12.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE02);
		tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x = 43.f;
		tree->transform->position.z += 48.f - 15.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE03);
		tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		tree->transform->position.x = 46.f;
		tree->transform->position.z += 48.f - 17.f;
		dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE04);

		////높이맵 기준 오른쪽
		//for (int i = 0; i < 6; i++)
		//{
		//	GameObject* tree = ObjectManager::GetInstance()->CreateObject<Tree>();
		//	tree->transform->position.x += 45.f;
		//	tree->transform->position.z += 16.f + 2 * i;
		//	dynamic_cast<Tree*>(tree)->setTreeSprite(TextureKey::TREE03);
		//}
	}

	if (_key == TextureKey::WATER_MAP)
	{	
		//물
		GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
		water->transform->position.y = _waterHeight;
		dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::WATER_WATER_ENVIRONMENT);
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

	if (_key == TextureKey::BROOK_MAP)
	{
		//물
		GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
		water->transform->position.y = _waterHeight;
		dynamic_cast<Water*>(water)->terrain->SetTexture(TextureKey::GRASS_WATER_ENVIRONMENT);
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
}
