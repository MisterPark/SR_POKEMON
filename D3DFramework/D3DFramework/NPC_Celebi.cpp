#include "stdafx.h"
#include "NPC_Celebi.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "Item_Tomato.h"
#include "AllStage.h"
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

			QuestManager::GetInstance()->AddProgress(eventNPC,myName);
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
			Dialog::SetEndEvent(ToDitto);
			


			Item_Tomato* tomato = (Item_Tomato*)ObjectManager::GetInstance()->CreateObject<Item_Tomato>();
			tomato->transform->position = { 20.f,0.f,48.f - 21.f };

			
			break;
		}
		case 1: {
			GameObject* isTomato = ObjectManager::GetInstance()->FindObject<Item_Tomato>();
			if (isTomato != nullptr)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"좋아! 일단 저기 보이는 과일 좀 주워 올래?", L"세레비", Pokemon::Celebi);
			}
			else if (isTomato == nullptr)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"고마워!", L"세레비", Pokemon::Celebi);
				Dialog::EnqueueText(L"음… 한번 먹어볼래?", L"세레비", Pokemon::Celebi);
				Dialog::EnqueueText(L"(습득한 아이템은 I(i) 키를 눌러 확인할 수 있습니다.)");
				Dialog::EnqueueText(L"(아이템은 커서를 올리면 정보가 나오게 되며……)");
				Dialog::EnqueueText(L"(소모성 아이템은 우클릭으로 사용이 가능합니다!)");
				QuestManager::GetInstance()->AddProgress(eventNPC,myName);

			}
			break;
		}
		case 2: {
				Dialog::Show();
				Dialog::EnqueueText(L"얼른 먹어봐!", L"세레비", Pokemon::Celebi);

				
			break;
		}
		case 3: {
			Dialog::Show();
			Dialog::EnqueueText(L"잘했어! 뒤에 있는 파이리한테 먼저 가봐!\n너의 능력을 유용하게 쓸수 있게 도와줄거야!", L"세레비", Pokemon::Celebi);
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 4: {
			Dialog::Show();
			Dialog::EnqueueText(L"파이리한테 먼저 가봐!", L"세레비", Pokemon::Celebi);
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
			Dialog::Show();
			Dialog::EnqueueText(L"이제 모험을 시작해보자!", L"세레비", Pokemon::Celebi);
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"우선 모두의 진화를 도와주고 다시 와줘!", L"세레비", Pokemon::Celebi);
			break;
		}
		case 2: {
			Dialog::Show();
			Dialog::EnqueueText(L"자…! 가자! 마지막 보스를 무찌르자!", L"세레비", Pokemon::Celebi);
			break;
		}
		case 3: {
			Dialog::Show();
			Dialog::EnqueueText(L"이런! 다시 도전해보자!", L"세레비", Pokemon::Celebi);
			QuestManager::GetInstance()->SetProgress(Event::EVENT_GAME, NpcName::CELEBI, 2);
			break;
		}
		case 4: {
			Dialog::Show();
			Dialog::EnqueueText(L"그란돈을 물리쳤구나! 정말 잘했어! 고마워!", L"세레비", Pokemon::Celebi);
			Dialog::SetEndEvent(Ending);
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
