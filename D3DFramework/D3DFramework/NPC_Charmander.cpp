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

			Dialog::EnqueueText(L"������ ���̳� ���� ���� ��!", name, Pokemon::Charmander);
			Dialog::Show();
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"�ϴ� �̰ź��� �޾�!", name, Pokemon::Charmander);
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

				Dialog::EnqueueText(L"�������� �ֿ� ��!", name, Pokemon::Charmander);
				Dialog::Show();
			}
			else if (isAwake == nullptr)
			{

				Dialog::EnqueueText(L"�� ���� ������ �츮���� �´ٸ�\n�츮�� ���Ǹ� ���� ��ð� �츮�� �ϳ��� ������ �� ����!", name, Pokemon::Charmander);
				Dialog::EnqueueText(L"�ٷ� ���Ž�������!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
				Dialog::Show();
			}
			break;
		}
		case 3: {


			Dialog::EnqueueText(L"���α����� ������ϱ�!", name, Pokemon::Charmander);
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

				Dialog::EnqueueText(L"��ȭ�ǵ� ã�ұ���!", name, Pokemon::Charmander);
				Dialog::EnqueueText(L"�ٷ� ��ȭ�ؾ߰ھ�!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_FIRE, 1);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMANDER)
			{

				Dialog::EnqueueText(L"��ȭ�ǵ� �� ã�Ҿ�?", name, Pokemon::Charmander);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARMANDER)
			{

				Dialog::EnqueueText(L"�ٽ� ���Ž����ٰ�!", name, Pokemon::Charmander);
				Dialog::SetEndEvent(MetatoCharmander);
				Dialog::Show();
			}
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"��ȣ! ����!", name, Pokemon::Charmeleon);
			Dialog::EnqueueText(L"���п� ��������!", name, Pokemon::Charmeleon);
			Dialog::EnqueueText(L"�̿��̸� �� ���� ��ȭ�� ������!", name, Pokemon::Charmeleon);
			Dialog::EnqueueText(L"�̹��� ��ȭ�ǵ� 5���� �ɰž�!", name, Pokemon::Charmeleon);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 2:
		{
			if (Inventory::GetItemCount(ItemType::STONE_OF_FIRE) >= 5)
			{

				Dialog::EnqueueText(L"��ȭ�ǵ� 5���� ��ƿԱ���!", name, Pokemon::Charmeleon);
				Dialog::EnqueueText(L"���� ��ȭ�ΰ�!", name, Pokemon::Charmeleon);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_FIRE, 5);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARMELEON)
			{

				Dialog::EnqueueText(L"���� ��ȭ�ǵ� ��ƴ޶��!", name, Pokemon::Charmeleon);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARMELEON)
			{

				Dialog::EnqueueText(L"���ڵ�� ����!", name, Pokemon::Charmeleon);
				Dialog::SetEndEvent(MetatoCharmeleon);
				Dialog::Show();
			}
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"ũ����! ����!", name, Pokemon::Charizard);
			Dialog::EnqueueText(L"���� ���� ���� ���Ѱ� ����!", name, Pokemon::Charizard);
			Dialog::EnqueueText(L"������ �ο�����!?", name, Pokemon::Charizard);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::CHARMANDER);
			break;
		}
		case 4:
		{
			if (Player::GetInstance()->GetCharacter()->type == TYPE::CHARIZARD)
			{

				Dialog::EnqueueText(L"���� �� ����������!", name, Pokemon::Charizard);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::CHARIZARD)
			{

				Dialog::EnqueueText(L"�� ���� ��������!", name, Pokemon::Charizard);
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
