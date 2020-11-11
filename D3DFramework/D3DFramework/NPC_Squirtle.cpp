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
	name = L"���α�";
	myName = NpcName::SQUIRTLE;
	SetTexture(State::IDLE, TextureKey::PW01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PW01_WALK_D_02, 3, 2);

	SetTexture(State::ATTACK, TextureKey::PW01_ATTACK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::PW01_SKILL_D_01, 1);
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
			Dialog::EnqueueText(L"�ٷ� ����� ���ؼ� ����������!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"�����ơ��� ���� �� ĳ���Ǹ� ��ƺ�!", name, Pokemon::Squirtle);
			Dialog::SetEndEvent(SummonCaterpie);
			QuestManager::GetInstance()->SetMonsterKill(MonsterType::CATERPIE, 0);
			QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
			
			break;
		}
		case 2: {
			//�ǵ��� ���� �ؽ�Ʈ ������ �����ϴ�.
			break;
		}
		case 3: {
			Dialog::Show();
			Dialog::EnqueueText(L"����ء�!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"������ ���ǰ� ���� ���ͷ��� ������\n���ѽð��� '5��' ��� ���� �����!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"�׸��� �ѹ� ������ �ϰ� �Ǹ� ����� ���Ÿ��Ͱ� ���������!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"���� �� ������ ������ �� �� ���ơ���!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"������ ����!", name, Pokemon::Squirtle);
			QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
			break;
		}
		case 4: {
			//�ǵ��� ���� �ؽ�Ʈ ������ �����ϴ�.
			break;
		}
		case 5: {
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
	else if (eventNPC == Event::EVENT_GAME)
	{
		switch (myProgress)
		{
		case 0: {
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
