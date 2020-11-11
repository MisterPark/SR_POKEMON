#include "stdafx.h"
#include "NPC_Charmander.h"
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
		name = L"���̸�";
		myName = NpcName::CHARMANDER;
		SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PF01_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 1);
		SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 2);
	}
	else if (1 == QuestManager::GetInstance()->GetEvolution(NpcName::CHARMANDER)) {
		name = L"���ڵ�";
		myName = NpcName::CHARMANDER;
		SetTexture(State::IDLE, TextureKey::PF02_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PF02_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PF02_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PF02_SKILL_D_01, 2);
	}
	else {
		name = L"���ڸ�";
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
			Dialog::EnqueueText(L"������ ���̳� ���� ���� ��!", name, Pokemon::Charmander);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"�ϴ� �̰ź��� �޾�!", name, Pokemon::Charmander);
			
			Item_StoneOfAwake* stoneOfAwake = (Item_StoneOfAwake*)ObjectManager::GetInstance()->CreateObject<Item_StoneOfAwake>();
			stoneOfAwake->transform->position = { 24.f,0.f,23.f };
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 2: {
			GameObject* isAwake = ObjectManager::GetInstance()->FindObject<Item_StoneOfAwake>();
			if (isAwake != nullptr)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"�������� �ֿ� ��!", name, Pokemon::Charmander);
			}
			else if (isAwake == nullptr)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"�� ���� ������ �츮���� �´ٸ�\n�츮�� ���Ǹ� ���� ��ð� �츮�� �ϳ��� ������ �� ����!", name, Pokemon::Charmander);
				Dialog::EnqueueText(L"�ٷ� ���Ž�������!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
			}
			break;
		}
		case 3: {
			if (Inventory::GetItemCount(ItemType::STONE_OF_FIRE) >= 1)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"��ȭ�ǵ� ã�ұ���!", name, Pokemon::Charmander);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMANDER)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"��ȭ�ǵ� �� ã�Ҿ�?", name, Pokemon::Charmander);
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARMANDER)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"�ٽ� ���Ž����ٰ�!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
			}
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
				Dialog::Show();
				Dialog::EnqueueText(L"��ȭ�ǵ� ã�ұ���!", name, Pokemon::Charmander);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMANDER)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"��ȭ�ǵ� �� ã�Ҿ�?", name, Pokemon::Charmander);
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARMANDER)
			{
				Dialog::Show();
				Dialog::EnqueueText(L"�ٽ� ���Ž����ٰ�!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
			}
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
