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

NPC_Celebi::NPC_Celebi(const Vector3& pos, bool onCenterDir, const Vector3& dir)
{
	transform->position = pos;
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

	//stat.money;
	UpdateAnimation();
}

void NPC_Celebi::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_Celebi* NPC_Celebi::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Celebi* newNpc = new NPC_Celebi(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Celebi::OnEvent()
{
	direction = DirFromPlayer(false);
	int myProgress = QuestManager::GetInstance()->GetProgress(myName);

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
			Dialog::EnqueueText(L"잘했어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"저기 저 캐터피를 사냥해보겠니?", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"(좌측 상단의 UI가 보이시나요?)");
			Dialog::EnqueueText(L"(초록색 게이지는 체력이고……)");
			Dialog::EnqueueText(L"(그 아래 비어있는 칸은 경험치입니다!)");
			Dialog::EnqueueText(L"(다음으로 도끼모양의 공격력과……\n 신발모양의 이동속도)");
			Dialog::EnqueueText(L"(그리고 초상화 밑에 레벨정도가 있겠네요!)");
			Dialog::EnqueueText(L"(모든 스태이터스는 레벨에 따라 성장합니다!)");
			Dialog::EnqueueText(L"(설명은 이 정도로 하고……)");
			Dialog::EnqueueText(L"(속성박스로 이동하세요!)");
			Dialog::EnqueueText(L"(속성박스로 이동하면 몬스터가 생성됩니다.)");
			Dialog::EnqueueText(L"(좌클릭으로 공격, 우클릭으로 스킬이 사용가능합니다.)");

			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CELEBI);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"(속성박스로 이동하세요.)");
			Dialog::EnqueueText(L"(속성박스로 이동하면 몬스터가 생성됩니다.)");
			Dialog::EnqueueText(L"(좌클릭으로 공격, 우클릭으로 스킬이 사용가능합니다.)");

			break;
		}
		case 2: {
			Dialog::Show();
			Dialog::EnqueueText(L"잘했어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"적 포켓몬을 사냥하면 경험치를 획득하고 레벨업도 할 수 있어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"이제 마을로 가보자!", L"세레비", Pokemon::Celebi);
			Dialog::SetEndEvent(ProgressTutorialEvent);
			break;
		}
		case 3: {
			//의도적 공백(스테이지와 연계,텍스트 넣으면 터짐)
		}
		case 4: {
			Dialog::EnqueueText(L"이제 마을로 가보자!", L"세레비", Pokemon::Celebi);
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
			Dialog::EnqueueText(L"포켓몬 마을에 잘 왔어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"어라? 너 모습이?", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"(메타몽으로 변했다.)");
			Dialog::EnqueueText(L"뭐야! 메타몽이었잖아?", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"그럼 할 수 있는 일이 더 많아지겠는데?", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"좋아! 일단 저기 보이는 과일 좀 주워 올래?", L"세레비", Pokemon::Celebi);

			Item_Tomato* tomato = (Item_Tomato*)ObjectManager::GetInstance()->CreateObject<Item_Tomato>();
			tomato->transform->position = { 20.f,0.f,48.f - 21.f };

			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CELEBI);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"좋아! 일단 저기 보이는 과일 좀 주워 올래?", L"세레비", Pokemon::Celebi);
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
