#include "stdafx.h"
#include "NPC_Squirtle.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"
#include "AllNPC.h"
NPC_Squirtle::NPC_Squirtle()
{
	Initialize();
}

NPC_Squirtle::NPC_Squirtle(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_Squirtle::Update()
{
	NPC::Update();
	
}


NPC_Squirtle* NPC_Squirtle::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Squirtle* newNpc = new NPC_Squirtle(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Squirtle::OnEvent()
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

			Dialog::EnqueueText(L"���� ���̾�?", name, Pokemon::Squirtle);
			Dialog::Show();
			//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"���!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"���� ���� �ɷ��� �����Ե� ����� �� �־�!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"�ٷ� ����� ���ؼ� ����������!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"�����ơ��� ���� �� ĳ���Ǹ� ��ƺ�!", name, Pokemon::Squirtle);
			Dialog::SetEndEvent(SummonCaterpie);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"ĳ���� óġ");
			QuestManager::GetInstance()->SetMonsterKill(MonsterType::CATERPIE, 0);
			QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);

			break;
		}
		case 2: {
			//�ǵ��� ���� �ؽ�Ʈ ������ �����ϴ�.
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"����ء�!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"������ ���ǰ� ���� ���ͷ��� ������\n���ѽð��� '5��' ��� ���� �����!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"�׸��� �ѹ� ������ �ϰ� �Ǹ� ����� ���Ÿ��Ͱ� ���������!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"���� �� ������ ������ �� �� ���ơ���!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"������ ����!", name, Pokemon::Squirtle);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
			break;
		}
		case 4: {
			//�ǵ��� ���� �ؽ�Ʈ ������ �����ϴ�.
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
			if (Inventory::GetItemCount(ItemType::STONE_OF_WATER) >= 1)
			{

				Dialog::EnqueueText(L"��ȭ�� ���� ã�ұ���!", name, Pokemon::Squirtle);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_WATER, 1);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::SQUIRTLE)
			{

				Dialog::EnqueueText(L"������ ����!", name, Pokemon::Squirtle);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::SQUIRTLE)
			{

				Dialog::EnqueueText(L"�� ���� �����ٰ�!", name, Pokemon::Squirtle);
				Dialog::SetEndEvent(MetatoSquirtle);
				Dialog::Show();
			}
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"���Ҿ�!", name, Pokemon::Wartortle);
			Dialog::EnqueueText(L"��Ϻα� �����Ŵ�!", name, Pokemon::Wartortle);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 2: {
			if (Inventory::GetItemCount(ItemType::STONE_OF_WATER) >= 5)
			{

				Dialog::EnqueueText(L"����! ��ȭ�ǵ� 5��!", name, Pokemon::Wartortle);
				Dialog::EnqueueText(L"��ť! ��ť!", name, Pokemon::Wartortle);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_WATER, 5);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::MINISQUIRTLE);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::WARTORTLE)
			{

				Dialog::EnqueueText(L"ȭ�������ڰ�!.", name, Pokemon::Wartortle);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::WARTORTLE)
			{

				Dialog::EnqueueText(L"��! ��!.", name, Pokemon::Wartortle);
				Dialog::SetEndEvent(MetatoWartortle);
				Dialog::Show();
			}
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"��������.", name, Pokemon::Blastoise);
			Dialog::EnqueueText(L"�źϵ��� ���̶� �ҷ��ٿ�!", name, Pokemon::Blastoise);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 4: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::BLASTOISE)
			{

				Dialog::EnqueueText(L"� ���ڰ�!", name, Pokemon::Blastoise);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::BLASTOISE)
			{

				Dialog::EnqueueText(L"�����̴�!", name, Pokemon::Blastoise);
				Dialog::SetEndEvent(MetatoBlastoise);
				Dialog::Show();
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

void NPC_Squirtle::MetatoWartortle()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::WARTORTLE, Pokemon::Wartortle);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Squirtle::MetatoBlastoise()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::BLASTOISE, Pokemon::Blastoise);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Squirtle::SummonCaterpie()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 5.f, 0.5f, 1, 2);
	spawner->transform->position = { 25.f,0.f,22.f };
	ObjectManager::AddObject(spawner);
	
}

void NPC_Squirtle::Evolution()
{
	QuestManager::GetInstance()->AddEvolution(NpcName::SQUIRTLE);
	dynamic_cast<NPC_Squirtle*>(ObjectManager::GetInstance()->FindObject<NPC_Squirtle>())->Initialize();
	dynamic_cast<NPC_Squirtle*>(ObjectManager::GetInstance()->FindObject<NPC_Squirtle>())->MetamorphoEffect();
}
