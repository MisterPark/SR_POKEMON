#include "stdafx.h"
#include "AllStage.h"
#include "AllCharacters.h"
#include "AllMeshs.h"
#include "AllDecorations.h"
#include "AllEnvironments.h"
#include "AllNPC.h"
#include "SkyBox.h"
#include "Item_Tomato.h"

#include "UI_Title.h"

void Stage_Tutorial::OnLoaded()
{
	ObjectManager::GetInstance()->CreateObject<Light>();

	SkyBox::Show();
	SkyBox::SetTexture(TextureKey::SKYDAY_U);
	Cursor::Hide();

	SoundManager::PlayBGM(L"Tutorial.mp3");
	SoundManager::SetVolume(SoundChannel::BGM, 0.1f);

	/*CollisionManager* col = CollisionManager::GetInstance();*/
	QuestManager::GetInstance()->SetEvent(Event::EVENT_TUTORIAL);
	Character* playerCharacter = Player::GetInstance()->GetCharacter();
	if (playerCharacter != nullptr)
	{
		Player::GetInstance()->SetRadianY(D3DXToRadian(30));
		playerCharacter->direction = { 1.f,0.f,1.f };
		playerCharacter->transform->position.x = 24.f;
		playerCharacter->transform->position.z = 48.f - 24.f;

	}

	TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
	trigerBox->transform->position = { 24.f,0.f,30.f };
	trigerBox->AnimChange(TextureKey::POP_01, TextureKey::POP_34,0.05f, true);

	GameObject* celebi = NPC_Celebi::Create(Vector3{ 24.f, 0.f, 31.f }, false, Vector3{ 0.f, 0.f, -1.f });
	ObjectManager::AddObject(celebi);




	Set_Stage_Tutorial_Map(TextureKey::GRASS_MAP, "Texture\\Map\\HeightMap\\Town.bmp", -0.1f);
	Dialog::GetInstance();
	Dialog::Show();
	Dialog::EnqueueText(L"�������� �ͺ�!");
	Dialog::EnqueueText(L"(������ ���� �̵��ϼ���.)");
	Dialog::EnqueueText(L"(���콺�� �̿��Ͽ� ȸ���ϰ� WASDŰ�� �̿��Ͽ� �̵��� �� �ֽ��ϴ�.)");
	Dialog::EnqueueText(L"(�����񿡰� �ٰ��� FŰ�� ���� ��ȣ�ۿ��� �õ��غ�����.)");
	Dialog::SetEndEvent(UI_SHOW);
}

void Stage_Tutorial::OnUnloaded()
{
	SoundManager::StopSound(SoundChannel::BGM);
	ObjectManager::DestroyAll();
}

void Stage_Tutorial::Update()
{
	if (InputManager::GetKeyDown(VK_F3))
	{
		SceneManager::LoadScene<Stage_Town>();
		Dialog::GetInstance()->Destroy();
		QuestManager::GetInstance()->SetEvent(Event::EVENT_TOWN);
	}
	Stage_Tutorial_Wave();
	
}


void Stage_Tutorial::Set_Stage_Tutorial_Map(TextureKey _key, const std::string& _filePath, float _waterHeight)
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

void Stage_Tutorial::Stage_Tutorial_Wave()
{
	GameObject* isTriger = ObjectManager::GetInstance()->FindObject<TriggerBox>();
	GameObject* isSpawner = ObjectManager::GetInstance()->FindObject<Spawner>();

	if (nullptr == isTriger && spawnerCount == 0)
	{
		
		//Dialog::EnqueueText(L"���߱���!");
		//Dialog::EnqueueText(L"���� �� ĳ���Ǹ� ����غ��ڴ�?");
		//Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���.)");
		//Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
		//Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");

		Dialog::SetEndEvent(UI_SHOW2);
		TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
		trigerBox->transform->position = { 24.f,0.f,20.f };
		trigerBox->AnimChange(TextureKey::PROPERTY_GRASS, TextureKey::PROPERTY_GRASS, 10.f, false);
		spawnerCount++;
		
		
	}
	else if (nullptr == isTriger&&spawnerCount == 1)
	{
		Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 3,2);
		spawner->transform->position = { 24.f,0.f,24.f };
		ObjectManager::AddObject(spawner);
		triggerOn = false;
		spawnerCount++;
	}
	else if (isSpawner == nullptr)
	{
		if (spawnerCount == 2)
		{
			QuestManager::GetInstance()->AddProgress(Event::EVENT_TUTORIAL,NpcName::CELEBI);
			Dialog::Show();
			Dialog::EnqueueText(L"(���͸� ������ ��ī�� ������ ȹ���� �� �ֽ��ϴ�.)");
			Dialog::EnqueueText(L"(��ī�� ������ ���� �÷��� ������ �÷��ݴϴ�!)");
			Dialog::EnqueueText(L"(���� ������ ����ϸ� Ŭ�����غ�����!)");
			Dialog::EnqueueText(L"(�����񿡰� ���ư�����!)");

			TriggerBox* trigerBox = (TriggerBox*)ObjectManager::GetInstance()->CreateObject<TriggerBox>();
			trigerBox->OnTriggered = Portal;
			trigerBox->transform->position = { 24.f,0.f,35.f };
			trigerBox->Portal();
			spawnerCount++;

		}
		if (spawnerCount == 3 && QuestManager::GetInstance()->GetProgress(Event::EVENT_TUTORIAL, NpcName::CELEBI) == 3)
		{
			Dialog::Show();
			Dialog::EnqueueText(L"(������ �̵��ϼ���!)");
			Dialog::EnqueueText(L"(������ �Ķ��� ��Ż�� ���� �̵��� �� �ֽ��ϴ�.)");
			QuestManager::GetInstance()->AddProgress(Event::EVENT_TUTORIAL, NpcName::CELEBI);
		}
	}
}


void Stage_Tutorial::CreateSpawner()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 10.f, 0.5f, 10);
	spawner->transform->position = { 24.f,0.f,24.f };
	ObjectManager::AddObject(spawner);
}

void Stage_Tutorial::Portal()
{
	SceneManager::LoadScene<Stage_Town>();
	QuestManager::GetInstance()->SetEvent(Event::EVENT_TOWN);
	
}

void Stage_Tutorial::UI_SHOW()
{
	UI_Title* ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_ARROW);
	ui->transform->position.x = 700.f;
	ui->transform->position.y = 150.f;
	float size = 2.f;
	ui->transform->scale = { size,size,size };

	ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_MOUSE);
	ui->transform->position.x = 800.f;
	ui->transform->position.y = 150.f;
	ui->transform->scale = { size,size,size };

	ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_F);
	ui->transform->position.x = 900.f;
	ui->transform->position.y = 150.f;
	ui->transform->scale = { size,size,size };
}

void Stage_Tutorial::UI_SHOW2()
{
	UI_Title* ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_LBUTTON);
	ui->transform->position.x = 700.f;
	ui->transform->position.y = 200.f;
	float size = 2.f;
	ui->transform->scale = { size,size,size };

	ui = (UI_Title*)ObjectManager::GetInstance()->CreateObject<UI_Title>();
	ui->SetTexture(TextureKey::UI_RBUTTON);
	ui->transform->position.x = 800.f;
	ui->transform->position.y = 200.f;
	ui->transform->scale = { size,size,size };
}
