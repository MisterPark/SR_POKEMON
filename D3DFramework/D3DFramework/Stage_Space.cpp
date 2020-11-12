#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "SkyBox.h"

void Stage_Space::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<Light>();

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SPACE1_U);

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(45));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 25.f;
		playerCharacter->transform->position.z = 48.f - 25.f;

	}
	waterHeight = -10.15f;

	Set_Stage_Space_Map(TextureKey::SPACE3_MAP, "Texture\\Map\\HeightMap\\SpaceBoss.bmp", waterHeight);


	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->transform->position = { 18.f,0.f,48.f - 21.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_DARK, TextureKey::PROPERTY_DARK, 10.f, false);
}

void Stage_Space::OnUnloaded()
{
	SoundManager::StopSound(SoundChannel::BGM);
	ObjectManager::DestroyAll();
}

void Stage_Space::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Town>();
	}
	Stage_Space_Wave();
	soHot(waterHeight);
}


void Stage_Space::Set_Stage_Space_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//물
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->Lava();
}

void Stage_Space::Stage_Space_Wave()
{
	if (QuestManager::GetInstance()->GetMonsterKill(MonsterType::GROUDON) >= 1)
	{
		QuestManager::GetInstance()->SetProgress(Event::EVENT_GAME, NpcName::CELEBI, 4);
		PlayerInfoPanel::SetQuestMessage(L"세레비와 대화.");
	}


	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		SoundManager::StopSound(SoundChannel::BGM);
		SoundManager::PlayBGM(L"Boss.wav");
		SoundManager::SetVolume(SoundChannel::BGM, 0.1f);

		Spawner* spawner = Spawner::Create(MonsterType::GROUDON, 10.f, 0.5f, 1, 65);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);

		triggerOn = true;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 1)
		{
			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = TownPortal;
			trigerBox->transform->position = { 40.f,0.f,40.f };
			trigerBox->Portal();
			spawnerCount++;

		}

	}
}

void Stage_Space::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::GROUDON, 10.f, 0.5f, 1);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}



void Stage_Space::TownPortal()
{
	SceneManager::LoadScene<Stage_Town>();
}

void Stage_Space::soHot(float _waterheight)
{
	if (Player::GetInstance()->GetCharacter()->transform->position.y <= _waterheight && Player::GetInstance()->GetCharacter()->isInvincible == false)
	{
		if (Player::GetInstance()->GetCharacter()->GetStat().hp <= 0)
			Player::GetInstance()->GetCharacter()->SetHp(0);

		Player::GetInstance()->GetCharacter()->MinusHp(dfSOHOT_DAMAGE);
	}
}
