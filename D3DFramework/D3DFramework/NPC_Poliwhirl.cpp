#include "stdafx.h"
#include "AllNPC.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"

NPC_Poliwhirl::NPC_Poliwhirl()
{
	Initialize();
}

NPC_Poliwhirl::NPC_Poliwhirl(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_Poliwhirl::~NPC_Poliwhirl()
{

}

void NPC_Poliwhirl::Initialize()
{

	name = L"����ì��";
	myName = NpcName::POLIWHIRL;
	SetTexture(State::IDLE, TextureKey::WHIRL_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::WHIRL_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::WHIRL_ATTACK_D_01, 1);
		
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.4f;
	transform->scale = { 0.4f, 0.4f, 0.4f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_Poliwhirl::Update()
{
	NPC::Update();

}


NPC_Poliwhirl* NPC_Poliwhirl::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Poliwhirl* newNpc = new NPC_Poliwhirl(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Poliwhirl::OnEvent()
{
	direction = DirFromPlayer(false);
	SetIsMoving(false);

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

			Dialog::EnqueueText(L"���� ���� ģ���� ������ �;.", name, Pokemon::Poliwhirl);
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

			if (Player::GetInstance()->GetCharacter()->type == TYPE::POLIWHIRL)
			{
				Dialog::EnqueueText(L"�ѡ�! ���� �Ȱ��̻���.", name, Pokemon::Poliwhirl);
				Dialog::EnqueueText(L"ģ�����ڡ�!.", name, Pokemon::Poliwhirl);
				Dialog::Show();
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::POLIWHIRL);
			}
			else
			{
				Dialog::EnqueueText(L"���� ģ���� ������ �;��.", name, Pokemon::Poliwhirl);
				Dialog::Show();
			}
			break;
		}
		case 1: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::POLIWHIRL)
			{
				
				Dialog::EnqueueText(L"�ȳ硦 ���� ģ��!.", name, Pokemon::Poliwhirl);
				Dialog::Show();
			}
			else
			{
				Dialog::EnqueueText(L"�ʴ� ������?", name, Pokemon::Poliwhirl);
				Dialog::Show();
			}
		}

		default:
			break;
		}
	}



}

void NPC_Poliwhirl::ExpPotion()
{
	Item_ExpPotion* expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 23.f,0.f,32.f };
	expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 24.f,0.f,32.f };
	expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
	expPotion->transform->position = { 22.f,0.f,32.f };
}

