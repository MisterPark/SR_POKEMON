#include "stdafx.h"
#include "NPC_Squirtle.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"
NPC_Squirtle::NPC_Squirtle()
{
	Initialize();
}

NPC_Squirtle::NPC_Squirtle(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_Squirtle::~NPC_Squirtle()
{

}

void NPC_Squirtle::Initialize()
{
	if (0 == QuestManager::GetInstance()->GetEvolution(NpcName::SQUIRTLE)) {
		name = L"���α�";
		myName = NpcName::SQUIRTLE;
		SetTexture(State::IDLE, TextureKey::PW01_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PW01_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PW01_ATTACK_D_01, 3);
		SetTexture(State::SKILL, TextureKey::PW01_SKILL_D_01, 1);
	}
	else if (1 == QuestManager::GetInstance()->GetEvolution(NpcName::SQUIRTLE)) {
		name = L"��Ϻα�";
		myName = NpcName::SQUIRTLE;
		SetTexture(State::IDLE, TextureKey::PW02_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PW02_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PW02_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PW02_SKILL_D_01, 1);
	}
	else {
		name = L"�źϿ�";
		myName = NpcName::SQUIRTLE;
		SetTexture(State::IDLE, TextureKey::PW03_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PW03_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PW03_ATTACK_D_01, 1);
		SetTexture(State::SKILL, TextureKey::PW03_SKILL_D_01, 1);
	}
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.13f;
	transform->scale = { 0.2f, 0.2f, 0.2f };

	direction;
	//stat.money;
	UpdateAnimation();
}

void NPC_Squirtle::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_Squirtle* NPC_Squirtle::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Squirtle* newNpc = new NPC_Squirtle(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Squirtle::OnEvent()
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
			Dialog::EnqueueText(L"���� ���̾�?",name, Pokemon::Squirtle);
			//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"���!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"���� ���� �ɷ��� �����Ե� ����� �� �־�!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"���� ���� �ɷ��� �����Ե� ����� �� �־�!", name, Pokemon::Squirtle);
			break;
		}
		case 2: {
			if (Inventory::GetItemCount(ItemType::STONE_OF_WATER) >= 1)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"��ȭ�ǵ��� ã�ұ���!", name, Pokemon::Squirtle);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::SQUIRTLE)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"������ ����!", name, Pokemon::Squirtle);
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::SQUIRTLE)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"�� ���� �����ٰ�!", name, Pokemon::Squirtle);
				Dialog::SetEndEvent(MetatoSquirtle);
			}
			break;
		}
		default:
			break;
		}
	}
}

void NPC_Squirtle::MetatoSquirtle()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::SQUIRTLE, Pokemon::Squirtle);
	Player::GetInstance()->PermanentMetamorphosis();
}
