#include "stdafx.h"
#include "NPC_Bulbasaur.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"

NPC_Bulbasaur::NPC_Bulbasaur()
{
	Initialize();
}

NPC_Bulbasaur::NPC_Bulbasaur(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

	//stat.money;
	UpdateAnimation();
}

void NPC_Bulbasaur::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_Bulbasaur* NPC_Bulbasaur::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Bulbasaur* newNpc = new NPC_Bulbasaur(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Bulbasaur::OnEvent()
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
			Dialog::EnqueueText(L"안녕……",name, Pokemon::Bulbasaur);

			//
			QuestManager::GetInstance()->AddEvolution(NpcName::BULBASAUR);
			Initialize();
			MetamorphoEffect();
			//
			//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
			break;
		}
		case 1: {
			Dialog::Show();
			Dialog::EnqueueText(L"내 힘은 쓸모 없을거야……", name, Pokemon::Bulbasaur);
			Dialog::EnqueueText(L"미안해…… 힘을 빌려줄 수 없을거야……", name, Pokemon::Bulbasaur);
			//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::BULBASAUR);
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
