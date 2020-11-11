#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "AllNPC.h"
#include "SkyBox.h"

void Stage_Fire_02::OnLoaded()
{
	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYFIRE1_U);

	SoundManager::PlayBGM(L"FireStage2.mp3");
	SoundManager::SetVolume(SoundChannel::BGM, 0.1f);

	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(90));
		playerCharacter->direction = { 1.f,0.f,0.f };

		playerCharacter->transform->position.x = 5.f;
		playerCharacter->transform->position.z = 48.f - 44.f;

	}

	waterHeight = -0.1f;
	Set_Stage_Fire_02_Map(TextureKey::VOLCANO_MAP, "Texture\\Map\\HeightMap\\Brook.bmp", waterHeight);

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	/*trigerBox->OnTriggered = CreateSpawner;*/
	trigerBox->transform->position = { 24.f,0.f,48.f - 22.f };
	trigerBox->AnimChange(TextureKey::PROPERTY_FIRE, TextureKey::PROPERTY_FIRE, 10.f, false);


}

void Stage_Fire_02::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void Stage_Fire_02::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Fire_Boss>();
	}
	Stage_Fire_02_Wave();
	soHot(waterHeight);
}


void Stage_Fire_02::Set_Stage_Fire_02_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
{
	//지형
	GameObject* environment = ObjectManager::GetInstance()->CreateObject<Environment>();
	dynamic_cast<Environment*>(environment)->terrain->SetTexture(_key);
	dynamic_cast<Environment*>(environment)->terrain->LoadHeightMap(_filePath);

	//물
	GameObject* water = ObjectManager::GetInstance()->CreateObject<Water>();
	water->transform->position.y = _waterHeight;
	dynamic_cast<Water*>(water)->WaterTextureChange(TextureKey::VOLCANO_MAP, TextureKey::VOLCANO_MAP, false);



}

void Stage_Fire_02::Create_Monster_A_Spawner()
{
	Spawner* poliwagSpawner = Spawner::Create(MonsterType::ARCANINE, 3.f, 0.5f, 6,54);
	poliwagSpawner->transform->position = { 6.f,0.f,48.f - 13.f };
	ObjectManager::AddObject(poliwagSpawner);

}

void Stage_Fire_02::Create_Monster_B_Spawner()
{
	Spawner* poliwagSpawner = Spawner::Create(MonsterType::MAGCARGO, 5.f, 0.5f, 6,57);
	poliwagSpawner->transform->position = { 41.f,0.f,48.f - 8.f };
	ObjectManager::AddObject(poliwagSpawner);
}

void Stage_Fire_02::Create_Monster_C_Spawner()
{
	Spawner* poliwagSpawner = Spawner::Create(MonsterType::RAPIDASH, 3.f, 0.5f, 6,51);
	poliwagSpawner->transform->position = { 36.f,0.f,48.f - 42.f };
	ObjectManager::AddObject(poliwagSpawner);
}

void Stage_Fire_02::Stage_Fire_02_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		float size = 0.3f;
		TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
		trigerBox->OnTriggered = Create_Monster_A_Spawner;
		trigerBox->transform->position = { 17.f,0.f,48.f - 4.f };
		trigerBox->transform->scale += {size, size, size};
		trigerBox->AnimChange(TextureKey::PORTRAIT_059, TextureKey::PORTRAIT_059, 10.f, false);

		trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
		trigerBox->OnTriggered = Create_Monster_B_Spawner;
		trigerBox->transform->position = { 44.f,0.f,48.f - 14.f };
		trigerBox->transform->scale += {size, size, size};
		trigerBox->AnimChange(TextureKey::PORTRAIT_219, TextureKey::PORTRAIT_219, 10.f, false);

		trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
		trigerBox->OnTriggered = Create_Monster_C_Spawner;
		trigerBox->transform->position = { 43.f,0.f,48.f - 32.f };
		trigerBox->transform->scale += {size, size, size};
		trigerBox->AnimChange(TextureKey::PORTRAIT_078, TextureKey::PORTRAIT_078, 10.f, false);

		spawnerCount++;
	}
	else if (isTriger == nullptr&&isSpawner==nullptr)
	{
		
		if (spawnerCount == 1)
		{
			if (QuestManager::GetInstance()->GetProgress(Event::EVENT_GAME, NpcName::CELEBI)==2)
			{
				TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
				trigerBox->OnTriggered = Portal;
				trigerBox->transform->position = { 25.f,0.f,48 - 26.f };
				trigerBox->AnimChange(TextureKey::PROPERTY_FIRE, TextureKey::PROPERTY_FIRE, 10.f, false);
				
				trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
				trigerBox->OnTriggered = TownPortal;
				trigerBox->transform->position = { 28.f,0.f,48 - 21.f };
				trigerBox->Portal();

				Dialog::Show();
				Dialog::EnqueueText(L"(최종 보스로 가는 포탈이 열렸습니다!)");
				Dialog::EnqueueText(L"(단단히 준비하고 가주세요!)");
				QuestManager::GetInstance()->AddProgress(Event::EVENT_GAME, NpcName::CELEBI);
				spawnerCount++;
			}
			else
			{
				TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
				trigerBox->OnTriggered = TownPortal;
				trigerBox->transform->position = { 28.f,0.f,48 - 21.f };
				trigerBox->Portal();
				spawnerCount++;
			}
		}


	}
}

void Stage_Fire_02::CreateSpawner()
{
}

void Stage_Fire_02::Portal()
{
	SceneManager::LoadScene<Stage_Fire_Boss>();
}

void Stage_Fire_02::TownPortal()
{
	SoundManager::StopSound(SoundChannel::BGM);
	SceneManager::LoadScene<Stage_Town>();
}

void Stage_Fire_02::soHot(float _waterheight)
{
	if (Player::GetInstance()->GetCharacter()->transform->position.y <= _waterheight)
	{
		if (Player::GetInstance()->GetCharacter()->GetStat().hp <= 0)
			Player::GetInstance()->GetCharacter()->SetHp(0);
		Player::GetInstance()->GetCharacter()->MinusHp(dfSOHOT_DAMAGE);
	}
}
