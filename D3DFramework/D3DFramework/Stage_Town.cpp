#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "AllNPC.h"
#include "SkyBox.h"

void Stage_Town::OnLoaded()
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
	trigerBox->OnTriggered = GrassPortal;
	trigerBox->transform->position = { 3.f,0.f,24.9f };
	trigerBox->AnimChange(TextureKey::PROPERTY_GRASS, TextureKey::PROPERTY_GRASS,10.f,false);

	trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->OnTriggered = WaterPortal;
	trigerBox->transform->position = { 45.f,0.f,24.9f };
	trigerBox->AnimChange(TextureKey::PROPERTY_WATER, TextureKey::PROPERTY_WATER, 10.f, false);

	trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->OnTriggered = FirePortal;
	trigerBox->transform->position = { 21.9f,0.f,45.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_FIRE, TextureKey::PROPERTY_FIRE, 10.f, false);



	GameObject* celebi = NPC_Celebi::Create(Vector3{ 24.f, 0.f, 31.f }, false, Vector3{ 0.f, 0.f, -1.f });
	ObjectManager::AddObject(celebi);
	GameObject* npc = NPC_Charmander::Create(Vector3{ 23.f, 0.f, 22.f });
	ObjectManager::AddObject(npc);
	//
	npc = NPC_Bulbasaur::Create(Vector3{ 24.f, 0.f, 22.f });
	ObjectManager::AddObject(npc);
	//
	npc = NPC_Squirtle::Create(Vector3{ 25.f, 0.f, 22.f });
	ObjectManager::AddObject(npc);
	
	if (QuestManager::GetInstance()->GetEvent() == EVENT_TOWN)
	{
		Dialog::Show();
		Dialog::EnqueueText(L"(세레비에게 가보세요!)");
	}

	Set_Stage_Town_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Town.bmp", -0.1f);
	

}

void Stage_Town::OnUnloaded()
{

	ObjectManager::DestroyAll();
}

void Stage_Town::Update()
{


	if (InputManager::GetKey(VK_F2))
	{
		SceneManager::LoadScene<TitleScene>();
	}
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Grass_01>();
		Dialog::GetInstance()->Destroy();
	}

	if (QuestManager::GetInstance()->GetEvent() == Event::EVENT_TOWN)
	{
		Event_Town(Event::EVENT_TOWN);
	}


}


void Stage_Town::Set_Stage_Town_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
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

void Stage_Town::Event_Town(Event _event)
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

}


void Stage_Town::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Town::GrassPortal()
{
	SceneManager::LoadScene<Stage_Grass_01>();
}

void Stage_Town::WaterPortal()
{
	SceneManager::LoadScene<Stage_Water_01>();
}

void Stage_Town::FirePortal()
{
	SceneManager::LoadScene<Stage_Fire_01>();
}
