#include "stdafx.h"
#include "NPC_Squirtle.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"

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
	int myProgress = QuestManager::GetInstance()->GetProgress(myName);

	Character* player = Player::GetInstance()->GetCharacter();


	switch (myProgress)
	{
	case 0: {
		Dialog::EnqueueText(L"∞≈∫œ¿Ã¥¬ º”¿Ã ∞≈∫œ§ª§ª");
		Dialog::Show();
		break;
	}

	default:
		break;
	}
}
