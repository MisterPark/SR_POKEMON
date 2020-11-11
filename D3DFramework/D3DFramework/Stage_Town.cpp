#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "AllNPC.h"
#include "SkyBox.h"
#include "Inventory.h"

void Stage_Town::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYDAY_U);
	Cursor::Hide();

	SoundManager::PlayBGM(L"Town.mp3");
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
	
	if (Player::GetInstance()->GetCharacter()->type == TYPE::DITTO&&QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN,NpcName::CELEBI)==0)
	{
		Dialog::Show();
		Dialog::EnqueueText(L"뭐야! 메타몽이었잖아?", L"세레비", Pokemon::Celebi);
		Dialog::EnqueueText(L"그럼 할 수 있는 일이 더 많아지겠는데?", L"세레비", Pokemon::Celebi);
		Dialog::EnqueueText(L"좋아! 일단 저기 보이는 과일 좀 주워 올래?", L"세레비", Pokemon::Celebi);
		Dialog::EnqueueText(L"(아이템은 다가가는 것으로 습득할 수 있습니다.)");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::CELEBI);
	}
	else if (QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::CELEBI) == 2&&Inventory::GetItemCount(ItemType::TOMATO)==0)
	{
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::CELEBI);
	}
	else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMANDER && QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::CHARMANDER) == 2)
	{
		Dialog::Show();
		Dialog::EnqueueText(L"어때! 괜찮지?", L"파이리", Pokemon::Charmander);
		Dialog::EnqueueText(L"다른 애들도 이제 모두 변신하게 해줄거야!", L"파이리", Pokemon::Charmander);
		Dialog::EnqueueText(L"이제 내 부탁을 들어줘! 난 항상 진화가 하고 싶었는데…", L"파이리", Pokemon::Charmander);
		Dialog::EnqueueText(L"숲 근처에서 진화의 돌을 본 포켓몬이 있어!", L"파이리", Pokemon::Charmander);
		Dialog::EnqueueText(L"그 진화의돌을 내게 가져와 줘!", L"파이리", Pokemon::Charmander);
		Dialog::EnqueueText(L"뭐 겸사겸사 다른 애들 것도 가져와도 되고!", L"파이리", Pokemon::Charmander);
		Dialog::EnqueueText(L"아! 가기 전에 꼬부기한테 한번 가봐!", L"파이리", Pokemon::Charmander);
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::CHARMANDER);
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::BULBASAUR);
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
	}
	else if (QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::SQUIRTLE) == 2&& QuestManager::GetInstance()->GetMonsterKill(MonsterType::CATERPIE)==1)
	{
		Dialog::Show();
		Dialog::EnqueueText(L"(또 뵙네요!)");
		Dialog::EnqueueText(L"(몬스터들을 사냥했을때 Lv의 하단에 초상화가 보이시나요?)");
		Dialog::EnqueueText(L"(저 초상화가 바로 당신이 변신할 수 있는 몬스터입니다!)");
		Dialog::EnqueueText(L"('Space' 키를 눌러 변신해보세요!)");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
	}

	else if (QuestManager::GetInstance()->GetProgress(Event::EVENT_TOWN, NpcName::SQUIRTLE) == 4)
	{
		Dialog::Show();
		Dialog::EnqueueText(L"(튜토리얼이 모두 끝났습니다!)");
		Dialog::EnqueueText(L"(앞으로는 당신이 하고 싶은대로 할 수 있습니다!)");
		Dialog::EnqueueText(L"(즐거운 모험되시길 바라겠습니다……!)");
		QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
		QuestManager::GetInstance()->SetEvent(Event::EVENT_GAME);
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
