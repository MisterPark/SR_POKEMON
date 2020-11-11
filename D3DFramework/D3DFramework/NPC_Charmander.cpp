#include "stdafx.h"
#include "NPC_Charmander.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "Item_StoneOfAwake.h"
NPC_Charmander::NPC_Charmander()
{
	Initialize();
}

NPC_Charmander::NPC_Charmander(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

	//stat.money;
	UpdateAnimation();
}

void NPC_Charmander::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_Charmander* NPC_Charmander::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Charmander* newNpc = new NPC_Charmander(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Charmander::OnEvent()
{
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
			Dialog::Show();
			Dialog::EnqueueText(L"세레비 일이나 마저 돕고 와!", name, Pokemon::Charmander);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"일단 이거부터 받아!", name, Pokemon::Charmander);
			
			Item_StoneOfAwake* stoneOfAwake = (Item_StoneOfAwake*)ObjectManager::GetInstance()->CreateObject<Item_StoneOfAwake>();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 2: {
			GameObject* isAwake = ObjectManager::GetInstance()->FindObject<Item_StoneOfAwake>();
			if (isAwake != nullptr)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"빨리빨리 주워 와!", name, Pokemon::Charmander);
			}
			else if (isAwake == nullptr)
			{
				Dialog::Show();
				
				QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			}
			break;
		}

		default:
			break;
		}
	}


	//switch (myProgress)
	//{
	//case 0: {
	//	Dialog::EnqueueText(L"뭐");
	//	Dialog::Show();
	//	QuestManager::GetInstance()->AddProgress(myName);
	//	break;
	//}
	//case 1: {
	//	Dialog::EnqueueText(L"좋은말로 할때 가라");
	//	Dialog::Show();
	//	break;
	//}

	//default:
	//	break;
	//}
}
