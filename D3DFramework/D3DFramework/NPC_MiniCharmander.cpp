#include "stdafx.h"

#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "AllItems.h"
#include "AllNPC.h"
NPC_MiniCharmander::NPC_MiniCharmander()
{
	Initialize();
}

NPC_MiniCharmander::NPC_MiniCharmander(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_MiniCharmander::~NPC_MiniCharmander()
{

}

void NPC_MiniCharmander::Initialize()
{

	name = L"파이리";
	myName = NpcName::MINICHARMANDER;
	SetTexture(State::IDLE, TextureKey::PF01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PF01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PF01_ATTACK_D_01, 1);
	SetTexture(State::SKILL, TextureKey::PF01_SKILL_D_01, 2);

	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.065f;
	transform->scale = { 0.1f, 0.1f, 0.1f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_MiniCharmander::Update()
{
	NPC::Update();

}


NPC_MiniCharmander* NPC_MiniCharmander::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_MiniCharmander* newNpc = new NPC_MiniCharmander(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_MiniCharmander::OnEvent()
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

			Dialog::EnqueueText(L"반갑다!", name, Pokemon::Charmander);
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

			Dialog::EnqueueText(L"리자드형처럼 될거야!", name, Pokemon::Charmander);
			Dialog::Show();


			break;
		}
		case 1: {

			Dialog::EnqueueText(L"리자몽! 리자몽!", name, Pokemon::Charmander);
			Dialog::Show();


			break;
		}
		default:
			break;
		}
	}
}
