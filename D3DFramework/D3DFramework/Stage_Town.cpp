#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "AllNPC.h"
#include "SkyBox.h"
#include "AllItems.h"
void Stage_Town::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<Light>();

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYDAY_U);
	Cursor::Hide();

	SoundManager::StopAll();
	SoundManager::PlayBGM(L"Town.wav");
	SoundManager::SetVolume(SoundChannel::BGM, 0.1f);
	
	/*CollisionManager* col = CollisionManager::GetInstance();*/

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(30));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 24.f;
		playerCharacter->transform->position.z = 48.f - 24.f;

	}

	// TODO: Ÿ� ���� ���ǿ� ���� ��Ÿ������ ����
	if (QuestManager::GetInstance()->GetEvent() != Event::EVENT_TOWN)
	{
		if (true) Player::GetInstance()->MetamorphosisToDitto();
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
	npc = NPC_Bulbasaur::Create(Vector3{ 19.f, 0.f, 22.f });
	ObjectManager::AddObject(npc);
	//
	npc = NPC_Squirtle::Create(Vector3{ 24.f, 0.f, 22.f });
	ObjectManager::AddObject(npc);

	npc = NPC_ColorDitto::Create(Vector3{ 29.f, 0.f, 30.f });
	ObjectManager::AddObject(npc);
	
	if (QuestManager::GetInstance()->GetEvent() == EVENT_TOWN)
	{
		
		Dialog::EnqueueText(L"(�����񿡰� ��������!)");
		Dialog::Show();
		PlayerInfoPanel::SetQuestMessage(L"������� ��ȭ");

	}
	Set_Stage_Town_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Town.bmp", -0.1f);
}

void Stage_Town::OnUnloaded()
{
	SoundManager::StopAll();
	ObjectManager::DestroyAll();
}

void Stage_Town::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Grass_01>();
		Dialog::GetInstance()->Destroy();
	}

	if (InputManager::GetKeyDown(VK_F4))
	{
		Item_StoneOfFire* fire = (Item_StoneOfFire*)ObjectManager::GetInstance()->CreateObject<Item_StoneOfFire>();
		fire->transform->position = { 20.f,0.f,48.f - 21.f };

		Item_StoneOfWater* water = (Item_StoneOfWater*)ObjectManager::GetInstance()->CreateObject<Item_StoneOfWater>();
		water->transform->position = { 20.f,0.f,48.f - 20.f };

		Item_StoneOfLeaf* leaf = (Item_StoneOfLeaf*)ObjectManager::GetInstance()->CreateObject<Item_StoneOfLeaf>();
		leaf->transform->position = { 20.f,0.f,48.f - 19.f };
	
	}
	if (QuestManager::GetInstance()->GetEvent() == Event::EVENT_TOWN)
	{
		Event_Town(Event::EVENT_TOWN);
	}
	if (QuestManager::GetInstance()->GetEvent() == Event::EVENT_GAME)
	{
		Event_Game(Event::EVENT_GAME);
	}

}


void Stage_Town::Set_Stage_Town_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
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
	
	if (Player::GetInstance()->GetCharacter()->type == TYPE::DITTO&&QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN,NpcName::CELEBI)==0)
	{
		
		Dialog::EnqueueText(L"����! ��Ÿ���̾��ݾ�?", L"������", Pokemon::Celebi);
		Dialog::EnqueueText(L"�׷� �� �� �ִ� ���� �� �������ڴµ�?", L"������", Pokemon::Celebi);
		Dialog::EnqueueText(L"����! �ϴ� ���� ���̴� ���� �� �ֿ� �÷�?", L"������", Pokemon::Celebi);
		Dialog::EnqueueText(L"(�������� �ٰ����� ������ ������ �� �ֽ��ϴ�.)");
		Dialog::Show();
		PlayerInfoPanel::SetQuestMessage(L"���� �ݰ� ������� ��ȭ");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::CELEBI);
	}
	else if (QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::CELEBI) == 2&&Inventory::GetItemCount(ItemType::TOMATO)==0)
	{
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::CELEBI);
	}
	else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMANDER && QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::CHARMANDER) == 2)
	{
		
		Dialog::EnqueueText(L"�! ������?", L"���̸�", Pokemon::Charmander);
		Dialog::EnqueueText(L"�ٸ� �ֵ鵵 ���� ��� �����ϰ� ���ٰž�!", L"���̸�", Pokemon::Charmander);
		Dialog::EnqueueText(L"���� �� ��Ź�� �����! �� �׻� ��ȭ�� �ϰ� �;��µ���", L"���̸�", Pokemon::Charmander);
		Dialog::EnqueueText(L"�� ��ó���� ��ȭ�� ���� �� ���ϸ��� �־�!", L"���̸�", Pokemon::Charmander);
		Dialog::EnqueueText(L"�� ��ȭ�ǵ��� ���� ������ ��!", L"���̸�", Pokemon::Charmander);
		Dialog::EnqueueText(L"�� ����� �ٸ� �ֵ� �͵� �����͵� �ǰ�!", L"���̸�", Pokemon::Charmander);
		Dialog::EnqueueText(L"��! ���� ���� ���α����� �ѹ� ����!", L"���̸�", Pokemon::Charmander);
		Dialog::Show();
		PlayerInfoPanel::SetQuestMessage(L"���α�� ��ȭ");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::CHARMANDER);
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::BULBASAUR);
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
	}
	else if (QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::SQUIRTLE) == 2&& QuestManager::GetInstance()->GetMonsterKill(MonsterType::CATERPIE)==1)
	{
		
		Dialog::EnqueueText(L"(�� �˳׿�!)");
		Dialog::EnqueueText(L"(���̸� �ʻ�ȭ�� �ϴܿ� ĳ���� �ʻ�ȭ�� ���̽ó���?)");
		Dialog::EnqueueText(L"(�� �ʻ�ȭ�� �ٷ� ����� ������ �� �ִ� �����Դϴ�!)");
		Dialog::EnqueueText(L"('Space' Ű�� ���� �����غ�����!)");
		Dialog::Show();
		PlayerInfoPanel::SetQuestMessage(L"���α�� �ٽ� ��ȭ");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
	}
	else if (QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::SQUIRTLE) == 4)
	{
		
		Dialog::EnqueueText(L"(Ʃ�丮���� ��� �������ϴ�!)");
		Dialog::EnqueueText(L"(������ ���̵��� Ǯ 1~20, ��20~40, ��40~60 ������ ���͵��� �����մϴ�.)");
		Dialog::EnqueueText(L"(�ڽ��� ������ ����ؼ� ������ �����ϼ���!)");
		Dialog::EnqueueText(L"(������ ������ ���ƿ��� �Ǵ� �����ϼ��䡦!)");
		Dialog::EnqueueText(L"(���� �����񿡰� ���� ������ �ް� �������� ��Ź�� ����ּ���!)");
		Dialog::Show();
		PlayerInfoPanel::SetQuestMessage(L"������� ��ȭ.");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
		QuestManager::GetInstance()->SetEvent(Event::EVENT_GAME);
	}
}

void Stage_Town::Event_Game(Event _event)
{
	if (QuestManager::GetInstance()->GetProgress(Event::EVENT_GAME, NpcName::BULBASAUR) == 4 &&
		QuestManager::GetInstance()->GetProgress(Event::EVENT_GAME, NpcName::CHARMANDER) == 4 &&
		QuestManager::GetInstance()->GetProgress(Event::EVENT_GAME, NpcName::SQUIRTLE) == 4 &&
		QuestManager::GetInstance()->GetProgress(Event::EVENT_GAME, NpcName::CELEBI) == 1
		)
	{
		
		Dialog::EnqueueText(L"(����� ��ȭ�� �������ϴ�!)");
		Dialog::Show();
		PlayerInfoPanel::SetQuestMessage(L"������� ��ȭ");
		QuestManager::GetInstance()->AddProgress(Event::EVENT_GAME, NpcName::CELEBI);
	}


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
