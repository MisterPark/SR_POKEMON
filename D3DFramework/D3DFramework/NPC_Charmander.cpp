#include "stdafx.h"
#include "AllNPC.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"

NPC_Charmander::NPC_Charmander()
{
	Initialize();
}

NPC_Charmander::NPC_Charmander(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_Charmander::~NPC_Charmander()
{

}

void NPC_Charmander::Initialize()
{
	if (0 == QuestManager::GetInstance()->GetEvolution(NpcName::CHARMANDER)) {
		name = L"파이리";
		myName = NpcName::CHARMANDER;
		SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PF01_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 1);
		SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 2);
	}
	else if (1 == QuestManager::GetInstance()->GetEvolution(NpcName::CHARMANDER)) {
		name = L"리자드";
		myName = NpcName::CHARMANDER;
		SetTexture(State::IDLE, TextureKey::PF02_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PF02_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PF02_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PF02_SKILL_D_01, 2);
	}
	else {
		name = L"리자몽";
		myName = NpcName::CHARMANDER;
		SetTexture(State::IDLE, TextureKey::PF03_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PF03_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PF03_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PF03_SKILL_D_01, 2);
	}
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.13f;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_Charmander::Update()
{
	NPC::Update();
	
}


NPC_Charmander* NPC_Charmander::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Charmander* newNpc = new NPC_Charmander(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Charmander::OnEvent()
{
	SetIsMoving(false);
	direction = DirFromPlayer(false);

	Event eventNPC = QuestManager::GetInstance()->GetEvent();

	Character* player = Player::GetInstance()->GetCharacter();

	if (eventNPC == Event::EVENT_END)
		return;
	int myProgress = QuestManager::GetInstance()->GetProgress(eventNPC, myName);
	if (eventNPC == Event::EVENT_TOWN)
	{
		switch (myProgress)
		{
		case 0: {

			Dialog::EnqueueText(L"세레비 일이나 마저 돕고 와!", name, Pokemon::Charmander);
			Dialog::Show();
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"일단 이거부터 받아!", name, Pokemon::Charmander);
			Dialog::Show();
			Item_StoneOfAwake* stoneOfAwake = (Item_StoneOfAwake*)ObjectManager::GetInstance()->CreateObject<Item_StoneOfAwake>();
			stoneOfAwake->transform->position = { 24.f,0.f,21.f };
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 2: {
			GameObject* isAwake = ObjectManager::GetInstance()->FindObject<Item_StoneOfAwake>();
			if (isAwake != nullptr)
			{

				Dialog::EnqueueText(L"빨리빨리 주워 와!", name, Pokemon::Charmander);
				Dialog::Show();
			}
			else if (isAwake == nullptr)
			{

				Dialog::EnqueueText(L"이 돌을 가지고 우리한테 온다면\n우리의 동의를 통해 장시간 우리중 하나로 변신할 수 있지!", name, Pokemon::Charmander);
				Dialog::EnqueueText(L"바로 변신시켜주지!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
				Dialog::Show();
			}
			break;
		}
		case 3: {


			Dialog::EnqueueText(L"꼬부기한테 가보라니까!", name, Pokemon::Charmander);
			Dialog::Show();
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
			if (Inventory::GetItemCount(ItemType::STONE_OF_FIRE) >= 1)
			{

				Dialog::EnqueueText(L"진화의돌 찾았구나!", name, Pokemon::Charmander);
				Dialog::EnqueueText(L"바로 진화해야겠어!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_FIRE, 1);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMANDER)
			{

				Dialog::EnqueueText(L"진화의돌 못 찾았어?", name, Pokemon::Charmander);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARMANDER)
			{

				Dialog::EnqueueText(L"다시 변신시켜줄게!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
				Dialog::Show();
			}
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"야호! 고마워!", name, Pokemon::Charmeleon);
			Dialog::EnqueueText(L"덕분에 강해졌어!", name, Pokemon::Charmeleon);
			Dialog::EnqueueText(L"이왕이면 그 다음 진화도 시켜줘!", name, Pokemon::Charmeleon);
			Dialog::EnqueueText(L"이번엔 진화의돌 5개면 될거야!", name, Pokemon::Charmeleon);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 2:
		{
			if (Inventory::GetItemCount(ItemType::STONE_OF_FIRE) >= 5)
			{

				Dialog::EnqueueText(L"진화의돌 5개를 모아왔구나!", name, Pokemon::Charmeleon);
				Dialog::EnqueueText(L"드디어 진화인가!", name, Pokemon::Charmeleon);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_FIRE, 5);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMELEON)
			{

				Dialog::EnqueueText(L"빨리 진화의돌 모아달라고!", name, Pokemon::Charmeleon);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARMELEON)
			{

				Dialog::EnqueueText(L"리자드로 변신!", name, Pokemon::Charmeleon);
				Dialog::SetEndEvent(MetatoCharmeleon);
				Dialog::Show();
			}
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"크하하! 고마워!", name, Pokemon::Charizard);
			Dialog::EnqueueText(L"이제 내가 가장 강한것 같아!", name, Pokemon::Charizard);
			Dialog::EnqueueText(L"누구와 싸워볼까!?", name, Pokemon::Charizard);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 4:
		{
			if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARIZARD)
			{

				Dialog::EnqueueText(L"가서 다 쓸어버리라고!", name, Pokemon::Charizard);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARIZARD)
			{

				Dialog::EnqueueText(L"내 힘을 빌려주지!", name, Pokemon::Charizard);
				Dialog::SetEndEvent(MetatoCharizard);
				Dialog::Show();
			}
			break;
		}
		default:
			break;
		}
	}



}

void NPC_Charmander::MetatoCharmander()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::CHARMANDER,Pokemon::Charmander);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Charmander::MetatoCharmeleon()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::CHARMELEON, Pokemon::Charmeleon);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Charmander::MetatoCharizard()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::CHARIZARD, Pokemon::Charizard);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Charmander::Evolution()
{
	QuestManager::GetInstance()->AddEvolution(NpcName::CHARMANDER);
	dynamic_cast<NPC_Charmander*>(ObjectManager::GetInstance()->FindObject<NPC_Charmander>())->Initialize();
	dynamic_cast<NPC_Charmander*>(ObjectManager::GetInstance()->FindObject<NPC_Charmander>())->MetamorphoEffect();
}
