#include "stdafx.h"
#include "NPC_Celebi.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"
#include "AllStage.h"
NPC_Celebi::NPC_Celebi()
{
	Initialize();
}

NPC_Celebi::NPC_Celebi(const Vector3& pos, bool onCenterDir, const Vector3& dir)
{
	transform->position = pos;
	spawnPos = pos;
	if (onCenterDir) {
		Vector3 Dir = Vector3{ 24.f, 0.f, 24.f } - transform->position;
		Vector3::Normalize(&Dir);
		direction = Dir;
	}
	else {
		direction = dir;
	}
	Initialize();
}

NPC_Celebi::~NPC_Celebi()
{
	
}

void NPC_Celebi::Initialize()
{
	
	myName = NpcName::CELEBI;
	SetTexture(State::WALK, TextureKey::CELE_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::CELE_WALK_D_01, 3, 1);
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::WALK;
	
	offsetY = 0.7f;
	transform->scale = { 0.5f, 0.5f, 0.5f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_Celebi::Update()
{
	NPC::Update();
	
}


NPC_Celebi* NPC_Celebi::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Celebi* newNpc = new NPC_Celebi(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Celebi::OnEvent()
{
	direction = DirFromPlayer(false);
	SetIsMoving(false);


	Character* player = Player::GetInstance()->GetCharacter();
	Event eventNPC = QuestManager::GetInstance()->GetEvent();

	if (eventNPC == Event::EVENT_END)
		return;
	int myProgress = QuestManager::GetInstance()->GetProgress(eventNPC, myName);
	if (eventNPC == Event::EVENT_TUTORIAL)
	{
		switch (myProgress)
		{
		case 0: {

			Dialog::EnqueueText(L"���߾�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"���� �� ĳ���Ǹ� ����غ��ڴ�?", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"(���� ����� UI�� ���̽ó���?)");
			Dialog::EnqueueText(L"(�ʷϻ� �������� ü���̰���)");
			Dialog::EnqueueText(L"(�� �Ʒ� ����ִ� ĭ�� ����ġ�Դϴ�!)");
			Dialog::EnqueueText(L"(�������� ��������� ���ݷ°�����\n �Ź߸���� �̵��ӵ�)");
			Dialog::EnqueueText(L"(�׸��� �ʻ�ȭ �ؿ� ���������� �ְڳ׿�!)");
			Dialog::EnqueueText(L"(��� �������ͽ��� ������ ���� �����մϴ�!)");
			Dialog::EnqueueText(L"(������ �� ������ �ϰ���)");
			Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���!)");
			Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
			Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");
			Dialog::Show();

			PlayerInfoPanel::SetQuestMessage(L"ĳ���� 3���� óġ.");
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���.)");
			Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
			Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");
			Dialog::Show();
			break;
		}
		case 2: {

			Dialog::EnqueueText(L"���߾�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"�� ���ϸ��� ����ϸ� ����ġ�� ȹ���ϰ� �������� �� �� �־�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"���� ������ ������!", L"������", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"������ �̵�");
			Dialog::SetEndEvent(ProgressTutorialEvent);

			break;
		}
		case 3: {
			//�ǵ��� ����(���������� ����,�ؽ�Ʈ ������ ����)
		}
		case 4: {
			Dialog::EnqueueText(L"���� ������ ������!", L"������", Pokemon::Celebi);
			Dialog::Show();
		}
		default:
			break;
		}
	}
	else if (eventNPC == Event::EVENT_TOWN)
	{
		switch (myProgress)
		{
		case 0: {

			Dialog::EnqueueText(L"���ϸ� ������ �� �Ծ�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"���? �� �����?", L"������", Pokemon::Celebi);
			Dialog::SetEndEvent(ToDitto);
			Dialog::Show();


			Item_Tomato* tomato = (Item_Tomato*)ObjectManager::GetInstance()->CreateObject<Item_Tomato>();
			tomato->transform->position = { 20.f,0.f,48.f - 21.f };


			break;
		}
		case 1: {
			GameObject* isTomato = ObjectManager::GetInstance()->FindObject<Item_Tomato>();
			if (isTomato != nullptr)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"����! �ϴ� ���� ���̴� ���� �� �ֿ� �÷�?", L"������", Pokemon::Celebi);

			}
			else if (isTomato == nullptr)
			{

				Dialog::EnqueueText(L"����!", L"������", Pokemon::Celebi);
				Dialog::EnqueueText(L"���� �ѹ� �Ծ��?", L"������", Pokemon::Celebi);
				Dialog::EnqueueText(L"(������ �������� I(i) Ű�� ���� Ȯ���� �� �ֽ��ϴ�.)");
				Dialog::EnqueueText(L"(�������� Ŀ���� �ø��� ������ ������ �Ǹ硦��)");
				Dialog::EnqueueText(L"(�Ҹ� �������� ��Ŭ������ ����� �����մϴ�!)");
				Dialog::Show();
				PlayerInfoPanel::SetQuestMessage(L"iŰ ���� �丶�� �Ա�");
				QuestManager::GetInstance()->AddProgress(eventNPC, myName);

			}
			break;
		}
		case 2: {

			Dialog::EnqueueText(L"�� �Ծ��!", L"������", Pokemon::Celebi);
			Dialog::Show();

			break;
		}
		case 3: {

			Dialog::EnqueueText(L"���߾�! �ڿ� �ִ� ���̸����� ���� ����!\n���� �ɷ��� �����ϰ� ���� �ְ� �����ٰž�!", L"������", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"���̸��� ����");
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 4: {

			Dialog::EnqueueText(L"���̸����� ���� ����!", L"������", Pokemon::Celebi);
			Dialog::Show();
			break;
		}
		default:
			break;
		}

	}
	else if (eventNPC == Event::EVENT_GAME)
	{
		switch (myProgress)
		{
		case 0: {

			Dialog::EnqueueText(L"���� ������ �����غ���!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"���������� ���̵��� Ǯ 1~20, ��20~40, ��40~60 ������ ������!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"������ ������ ���ƿ��� �Ǵ� �����ϱ� �ٷ�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"�׷� ������ ���״� ������ �� ������ �ٽ� �� ��!", L"������", Pokemon::Celebi);
			Dialog::SetEndEvent(ExpPotion);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"�׷� �켱 ����� ��ȭ�� �����ְ� �ٽ� ����!", L"������", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"����� ��ȭ�� �����ְ� ������� ��ȭ.");
			break;
		}
		case 2: {

			Dialog::EnqueueText(L"�ڡ�! ����! ������ ������ �����!", L"������", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"�Ҳ� 2�������� ����.");
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"�̷�! �ٽ� �����غ���!", L"������", Pokemon::Celebi);
			Dialog::Show();
			QuestManager::GetInstance()->SetProgress(Event::EVENT_GAME, NpcName::CELEBI, 2);
			break;
		}
		case 4: {

			Dialog::EnqueueText(L"�׶����� �����Ʊ���! ���� ���߾�! ����!", L"������", Pokemon::Celebi);
			Dialog::SetEndEvent(Ending);
			Dialog::Show();
			break;
		}
		default:
			break;
		}
	}
}

void NPC_Celebi::ProgressTutorialEvent()
{
	Dialog::Hide();
	QuestManager::GetInstance()->AddProgress(Event::EVENT_TUTORIAL, NpcName::CELEBI);
	
		
}

void NPC_Celebi::ToDitto()
{
	Player::GetInstance()->MetamorphosisToDitto();
}

void NPC_Celebi::Ending()
{
	SceneManager::LoadScene<EndingScene>();
}

void NPC_Celebi::ExpPotion()
{
	Item_ExpPotion* expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 24.f,0.f,32.f };
	expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 24.f,0.f,32.f };
	expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 24.f,0.f,32.f };
}
