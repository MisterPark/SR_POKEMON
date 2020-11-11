#include "stdafx.h"
#include "NPC_Celebi.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "Item_Tomato.h"
NPC_Celebi::NPC_Celebi()
{
	Initialize();
}

NPC_Celebi::NPC_Celebi(const Vector3& pos)
{
	transform->position = pos;
	Initialize();
}

NPC_Celebi::~NPC_Celebi()
{
	CollisionManager::GetInstance()->DisregisterObject(this);
}

void NPC_Celebi::Initialize()
{
	//SetTexture(State::IDLE, TextureKey::COINPOKE_1, 27);
	
	SetTexture(State::WALK, TextureKey::CELE_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::CELE_WALK_D_01, 3, 1);
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::WALK;
	
	offsetY = 0.7f;
	transform->scale = { 0.5f, 0.5f, 0.5f };

	//stat.money;
	UpdateAnimation();
}

void NPC_Celebi::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_Celebi* NPC_Celebi::Create(const Vector3& pos)
{
	NPC_Celebi* newNpc = new NPC_Celebi(pos);
	return newNpc;
}

void NPC_Celebi::OnEvent()
{
	direction = DirFromPlayer(false);
	

	Character* player = Player::GetInstance()->GetCharacter();
	Event eventNPC = QuestManager::GetInstance()->GetEvent();

	if (eventNPC == Event::EVENT_END)
		return;
	int myProgress = QuestManager::GetInstance()->GetProgress(eventNPC,NpcName::CELEBI);
	if (eventNPC == Event::EVENT_TUTORIAL)
	{
		switch (myProgress)
		{
		case 0: {
			Dialog::Show();
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

			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CELEBI);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���.)");
			Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
			Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");

			break;
		}
		case 2: {
			Dialog::Show();
			Dialog::EnqueueText(L"���߾�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"�� ���ϸ��� ����ϸ� ����ġ�� ȹ���ϰ� �������� �� �� �־�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"���� ������ ������!", L"������", Pokemon::Celebi);
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
			Dialog::Show();
			Dialog::EnqueueText(L"���ϸ� ������ �� �Ծ�!", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"���? �� �����?", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"(��Ÿ������ ���ߴ�.)");
			Dialog::EnqueueText(L"����! ��Ÿ���̾��ݾ�?", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"�׷� �� �� �ִ� ���� �� �������ڴµ�?", L"������", Pokemon::Celebi);
			Dialog::EnqueueText(L"����! �ϴ� ���� ���̴� ���� �� �ֿ� �÷�?", L"������", Pokemon::Celebi);

			Item_Tomato* tomato = (Item_Tomato*)ObjectManager::GetInstance()->CreateObject<Item_Tomato>();
			tomato->transform->position = { 20.f,0.f,48.f - 21.f };

			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CELEBI);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"����! �ϴ� ���� ���̴� ���� �� �ֿ� �÷�?", L"������", Pokemon::Celebi);
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
