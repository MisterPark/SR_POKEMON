#include "stdafx.h"
#include "NPC_Bulbasaur.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"

NPC_Bulbasaur::NPC_Bulbasaur()
{
	Initialize();
}

NPC_Bulbasaur::NPC_Bulbasaur(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_Bulbasaur::~NPC_Bulbasaur()
{

}

void NPC_Bulbasaur::Initialize()
{
	if (0 == QuestManager::GetInstance()->GetEvolution(NpcName::BULBASAUR)) {
		name = L"이상해씨";
		myName = NpcName::BULBASAUR;
		SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PG01_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PG01_SKILL_D_01, 2);
	}
	else if (1 == QuestManager::GetInstance()->GetEvolution(NpcName::BULBASAUR)) {
		name = L"이상해풀";
		myName = NpcName::BULBASAUR;
		SetTexture(State::IDLE, TextureKey::PG02_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PG02_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PG02_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PG02_SKILL_D_01, 2);
	}
	else {
		name = L"이상해꽃";
		myName = NpcName::BULBASAUR;
		SetTexture(State::IDLE, TextureKey::PG03_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PG03_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PG03_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PG03_SKILL_D_01, 2);
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

void NPC_Bulbasaur::Update()
{
	NPC::Update();
}


NPC_Bulbasaur* NPC_Bulbasaur::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Bulbasaur* newNpc = new NPC_Bulbasaur(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Bulbasaur::OnEvent()
{
	direction = DirFromPlayer(false);
	SetIsMoving(false);
	//SetIsMoving(true); 대화가 끝날때
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

			Dialog::EnqueueText(L"안녕……", name, Pokemon::Bulbasaur);
			Dialog::Show();
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"내 힘은 쓸모 없을거야……", name, Pokemon::Bulbasaur);
			Dialog::EnqueueText(L"미안해…… 힘을 빌려줄 수 없어……", name, Pokemon::Bulbasaur);
			Dialog::Show();
			break;
		}
		}
	}
	else if (eventNPC == Event::EVENT_GAME)
	{
		switch (myProgress)
		{
		case 0: {
			if (Inventory::GetItemCount(ItemType::STONE_OF_LEAF) >= 1)
			{

				Dialog::EnqueueText(L"그거 진화의돌……?", name, Pokemon::Bulbasaur);
				Dialog::EnqueueText(L"나 주는거야…?", name, Pokemon::Bulbasaur);
				Dialog::EnqueueText(L"정말…… 고마워!!", name, Pokemon::Bulbasaur);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_LEAF, 1);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
			}
			else
			{

				Dialog::EnqueueText(L"내 힘은 쓸모 없을거야……", name, Pokemon::Bulbasaur);
				Dialog::EnqueueText(L"미안해…… 힘을 빌려줄 수 없어……", name, Pokemon::Bulbasaur);
				Dialog::Show();
				//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
			}
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"나를 도와준… 친구….", name, Pokemon::Ivysaur);
			Dialog::EnqueueText(L"나도 이제 도와줄게…….", name, Pokemon::Ivysaur);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
			break;
		}
		case 2: {
			if (Inventory::GetItemCount(ItemType::STONE_OF_LEAF) >= 5)
			{

				Dialog::EnqueueText(L"진화의돌을 5개나……?", name, Pokemon::Ivysaur);
				Dialog::EnqueueText(L"정말 고마워…. 친구야….", name, Pokemon::Ivysaur);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_LEAF, 5);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::MINIBULBASAUR);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::IVYSAUR)
			{

				Dialog::EnqueueText(L"몸 조심해…….", name, Pokemon::Ivysaur);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::IVYSAUR)
			{

				Dialog::EnqueueText(L"변신….", name, Pokemon::Ivysaur);
				Dialog::SetEndEvent(MetatoIvysaur);
				Dialog::Show();
			}
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"이제 도망치지 않을거야…….", name, Pokemon::Venusaur);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
			break;
		}
		case 4: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::VENUSAUR)
			{

				Dialog::EnqueueText(L"다치지 않길 바랄게…….", name, Pokemon::Venusaur);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::VENUSAUR)
			{

				Dialog::EnqueueText(L"내 힘이야….", name, Pokemon::Venusaur);
				Dialog::SetEndEvent(MetatoVenusaur);
				Dialog::Show();
			}
			break;
		}
		default:
			break;
		}

	}

}

void NPC_Bulbasaur::MetatoBulbasaur()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::BULBASAUR, Pokemon::Bulbasaur);
	Player::GetInstance()->PermanentMetamorphosis();
	
}

void NPC_Bulbasaur::MetatoIvysaur()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::IVYSAUR, Pokemon::Ivysaur);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Bulbasaur::MetatoVenusaur()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::VENUSAUR, Pokemon::Venusaur);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Bulbasaur::Evolution()
{
	QuestManager::GetInstance()->AddEvolution(NpcName::BULBASAUR);
	dynamic_cast<NPC_Bulbasaur*>(ObjectManager::GetInstance()->FindObject<NPC_Bulbasaur>())->Initialize();
	dynamic_cast<NPC_Bulbasaur*>(ObjectManager::GetInstance()->FindObject<NPC_Bulbasaur>())->MetamorphoEffect();
	
}
