#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"
#include "CubeMan.h"
#include "Environment.h"
#include "TitleScene.h"
#include "Celebi.h"

void TestScene::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKY_U);
	Camera::GetInstance()->SetPosition(Vector3(24.f, 0,48.f - 36.f));
	Camera::GetInstance()->transform->look = Vector3(0, 0, 0);
	Player::GetInstance()->Initialize();

	// TestUI
	Player::GetInstance()->ChangeNextPokemon(TYPE::CHARMANDER, Pokemon::Charmander);
	Player::GetInstance()->PermanentMetamorphosis();

	Character* playerCharacter = Player::GetInstance()->GetCharacter();

	//7시
	Player::GetInstance()->SetRadianY(D3DXToRadian(180));
	playerCharacter->direction = { -1.f,0.f,-1.f };

	Player::GetInstance()->SetCharacter(playerCharacter);

	playerCharacter->transform->position.x = 24.f;
	playerCharacter->transform->position.z = 48.f - 10.f;

	
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 5);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);

	Celebi* npc = Celebi::Create({20.f, 20.f, 20.f});
	ObjectManager::AddObject(npc);
	CollisionManager::RegisterObject(COLTYPE::COIN, npc);

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->OnTriggered = Portal;
	trigerBox->transform->position = { 40.f,0.f,40.f };
	trigerBox->Portal();


	SetTestSceneMap(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Town.bmp",-0.1f);
}
void TestScene::OnUnloaded()
{

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
void TestScene::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::PONYTA, 10.f, 0.5f, 5);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);


}

void TestScene::Portal()
{
	SceneManager::LoadScene<Stage_Grass_01>();
}
