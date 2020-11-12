#include "stdafx.h"
#include "NPC_MiniBulbasaur.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"
#include "AllNPC.h"
NPC_MiniBulbasaur::NPC_MiniBulbasaur()
{
	Initialize();
}

NPC_MiniBulbasaur::NPC_MiniBulbasaur(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_MiniBulbasaur::~NPC_MiniBulbasaur()
{

}

void NPC_MiniBulbasaur::Initialize()
{

	name = L"이상해씨";
	myName = NpcName::MINIBULBASAUR;
	SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::PG01_SKILL_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.065f;
	transform->scale = { 0.1f, 0.1f, 0.1f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_MiniBulbasaur::Update()
{
	NPC::Update();

}


NPC_MiniBulbasaur* NPC_MiniBulbasaur::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_MiniBulbasaur* newNpc = new NPC_MiniBulbasaur(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_MiniBulbasaur::OnEvent()
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

			Dialog::EnqueueText(L"난 버그야…", name, Pokemon::Bulbasaur);
			Dialog::Show();
			//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
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

			Dialog::EnqueueText(L"친구를 만들고 싶어서……", name, Pokemon::Bulbasaur);
			Dialog::Show();


			break;
		}
		case 1: {

			Dialog::EnqueueText(L"나도 할 수 있을까…?", name, Pokemon::Bulbasaur);
			Dialog::Show();


			break;
		}
		default:
			break;
		}
	}
}
