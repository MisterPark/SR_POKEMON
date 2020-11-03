#include "stdafx.h"
#include "Stage_Grass_Boss.h"
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
#include "MonsterAI.h"
#include "Stage_Water_01.h"

void Stage_Grass_Boss::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYNIGHT_U);
	Charmander* playerCharacter = Charmander::Create(Vector3(0.f, 0.f, 0.f), Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, 0.f, 1.f));
	ObjectManager::AddObject(playerCharacter);

	Player::GetInstance()->SetRadianY(D3DXToRadian(45));
	playerCharacter->direction = { 1.f,0.f,1.f };

	Player::GetInstance()->SetCharacter(playerCharacter);
	playerCharacter->transform->position.x = 1.f;
	playerCharacter->transform->position.z = 48.f - 47.f;
	Set_Stage_Grass_Boss_Map(TextureKey::GRASS_MAP2, "Texture\\Map\\HeightMap\\Lake3.bmp", 3.5f);

	Scyther* monsterCharacter5 = Scyther::Create(Vector3(42.f, 0.f, 42.f), Vector3(1.f, 1.f, 1.f), Vector3(0.f, 0.f, 1.f));
	monsterCharacter5->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter5->AddComponent<MonsterAI>(L"MonsterAI"));
	monsterCharacter5->monsterAI->SetType(MonsterType::SCYTHER);
	ObjectManager::AddObject(monsterCharacter5);

}

void Stage_Grass_Boss::OnUnloaded()
{
	Camera::GetInstance()->SetTarget(nullptr);
	Player::GetInstance()->SetCharacter(nullptr);
	ObjectManager::DestroyAll();
}

void Stage_Grass_Boss::Update()
{
	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Water_01>();
	}
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
