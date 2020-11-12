#include "stdafx.h"
#include "NPC_MiniSquirtle.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"
#include "AllNPC.h"
NPC_MiniSquirtle::NPC_MiniSquirtle()
{
	Initialize();
}

NPC_MiniSquirtle::NPC_MiniSquirtle(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_MiniSquirtle::~NPC_MiniSquirtle()
{

}

void NPC_MiniSquirtle::Initialize()
{
	
	name = L"꼬부기";
	myName = NpcName::MINISQUIRTLE;
	SetTexture(State::IDLE, TextureKey::PW01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PW01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PW01_ATTACK_D_01, 3);
	SetTexture(State::SKILL, TextureKey::PW01_SKILL_D_01, 1);

	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.065f;
	transform->scale = { 0.1f, 0.1f, 0.1f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_MiniSquirtle::Update()
{
	NPC::Update();

}


NPC_MiniSquirtle* NPC_MiniSquirtle::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_MiniSquirtle* newNpc = new NPC_MiniSquirtle(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_MiniSquirtle::OnEvent()
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

			Dialog::EnqueueText(L"안녕!", name, Pokemon::Squirtle);
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

				Dialog::EnqueueText(L"어니부기 형님을 따라서 왔어!", name, Pokemon::Squirtle);
				Dialog::Show();
				

			break;
		}
		case 1: {

			Dialog::EnqueueText(L"거북왕 보스를 따르자!", name, Pokemon::Squirtle);
			Dialog::Show();


			break;
		}
		default:
			break;
		}
	}
}
