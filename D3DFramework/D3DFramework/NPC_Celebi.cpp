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

			Dialog::EnqueueText(L"잘했어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"저기 저 캐터피를 사냥해보겠니?", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"(좌측 상단의 UI가 보이시나요?)");
			Dialog::EnqueueText(L"(초록색 게이지는 체력이고……)");
			Dialog::EnqueueText(L"(그 아래 비어있는 칸은 경험치입니다!)");
			Dialog::EnqueueText(L"(다음으로 도끼모양의 공격력과……\n 신발모양의 이동속도)");
			Dialog::EnqueueText(L"(그리고 초상화 밑에 레벨정도가 있겠네요!)");
			Dialog::EnqueueText(L"(모든 스테이터스는 레벨에 따라 성장합니다!)");
			Dialog::EnqueueText(L"(설명은 이 정도로 하고……)");
			Dialog::EnqueueText(L"(속성박스로 이동하세요!)");
			Dialog::EnqueueText(L"(속성박스로 이동하면 몬스터가 생성됩니다.)");
			Dialog::EnqueueText(L"(좌클릭으로 공격, 우클릭으로 스킬이 사용가능합니다.)");
			Dialog::Show();

			PlayerInfoPanel::SetQuestMessage(L"캐터피 3마리 처치.");
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"(속성박스로 이동하세요.)");
			Dialog::EnqueueText(L"(속성박스로 이동하면 몬스터가 생성됩니다.)");
			Dialog::EnqueueText(L"(좌클릭으로 공격, 우클릭으로 스킬이 사용가능합니다.)");
			Dialog::Show();
			break;
		}
		case 2: {

			Dialog::EnqueueText(L"잘했어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"적 포켓몬을 사냥하면 경험치를 획득하고 레벨업도 할 수 있어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"이제 마을로 가보자!", L"세레비", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"마을로 이동");
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

			Dialog::EnqueueText(L"포켓몬 마을에 잘 왔어!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"어라? 너 모습이?", L"세레비", Pokemon::Celebi);
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
				Dialog::EnqueueText(L"좋아! 일단 저기 보이는 과일 좀 주워 올래?", L"세레비", Pokemon::Celebi);

			}
			else if (isTomato == nullptr)
			{

				Dialog::EnqueueText(L"고마워!", L"세레비", Pokemon::Celebi);
				Dialog::EnqueueText(L"음… 한번 먹어볼래?", L"세레비", Pokemon::Celebi);
				Dialog::EnqueueText(L"(습득한 아이템은 I(i) 키를 눌러 확인할 수 있습니다.)");
				Dialog::EnqueueText(L"(아이템은 커서를 올리면 정보가 나오게 되며……)");
				Dialog::EnqueueText(L"(소모성 아이템은 우클릭으로 사용이 가능합니다!)");
				Dialog::Show();
				PlayerInfoPanel::SetQuestMessage(L"i키 눌러 토마토 먹기");
				QuestManager::GetInstance()->AddProgress(eventNPC, myName);

			}
			break;
		}
		case 2: {

			Dialog::EnqueueText(L"얼른 먹어봐!", L"세레비", Pokemon::Celebi);
			Dialog::Show();

			break;
		}
		case 3: {

			Dialog::EnqueueText(L"잘했어! 뒤에 있는 파이리한테 먼저 가봐!\n너의 능력을 유용하게 쓸수 있게 도와줄거야!", L"세레비", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"파이리로 변신");
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 4: {

			Dialog::EnqueueText(L"파이리한테 먼저 가봐!", L"세레비", Pokemon::Celebi);
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

			Dialog::EnqueueText(L"대단한 능력이구나……!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"너라면 우리의 부탁을 들어줄 수 있을 것 같아!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"일단 선물을 줄테니 가져간 후 나한테 다시 와 줘!", L"세레비", Pokemon::Celebi);
			Dialog::SetEndEvent(ExpPotion);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			PlayerInfoPanel::SetQuestMessage(L"세레비와 대화");
			break;
		}
		case 1: {
			Dialog::EnqueueText(L"사실 우리는 원래 동쪽의 한 계곡에서 살고 있었어", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"하지만 얼마전 그란돈이라는 포켓몬이 오더니 \n 분노하면서 우리 마을을 모두 불태워버렸고…….", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"우리는 도망치는 수밖엔 없었어…….", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"그란돈은 거기서 멈추지 않고 계속해서\n다른곳에서도 파괴를 일삼고 있고…….", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"이대로라면 우리가 살 곳은 어디에도 없게 될거야…!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"하지만 너의 그 능력을 본 순간 생각했어…!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"너라면 그란돈을 물리칠 수 있을거라고…!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"그럼 잘 부탁해…!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"일단 마을의 포켓몬들이 진화하게끔 도와주지 않을래?", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"다들 진화하게 된다면 너 또한 강해질 수 있을거야!", L"세레비", Pokemon::Celebi);
			Dialog::EnqueueText(L"그럼 우선 모두의 진화를 도와주고 다시 와줘!", L"세레비", Pokemon::Celebi);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			PlayerInfoPanel::SetQuestMessage(L"모두의 진화를 도와주고 세레비와 대화.");
			break;
		}
		case 2: {

			Dialog::EnqueueText(L"그럼 우선 모두의 진화를 도와주고 다시 와줘!", L"세레비", Pokemon::Celebi);
			Dialog::Show();
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"자…! 가자! 마지막 보스를 무찌르자!", L"세레비", Pokemon::Celebi);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"불꽃 2스테이지 입장.");
			break;
		}
		case 4: {

			Dialog::EnqueueText(L"이런! 다시 도전해보자!", L"세레비", Pokemon::Celebi);
			Dialog::Show();
			QuestManager::GetInstance()->SetProgress(Event::EVENT_GAME, NpcName::CELEBI, 3);
			break;
		}
		case 5: {

			Dialog::EnqueueText(L"그란돈을 물리쳤구나! 정말 잘했어! 고마워!", L"세레비", Pokemon::Celebi);
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
	expPotion->transform->position = { 23.f,0.f,32.f };
	expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 24.f,0.f,32.f };
	expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 22.f,0.f,32.f };
}
