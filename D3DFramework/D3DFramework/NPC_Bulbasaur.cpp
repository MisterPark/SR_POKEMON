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

	myName = NpcName::BULBASAUR;
	SetTexture(State::IDLE, TextureKey::PG01_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::PG01_WALK_D_02, 3, 2);
	SetTexture(State::ATTACK, TextureKey::PG01_ATTACK_D_01, 2);
	SetTexture(State::SKILL, TextureKey::PG01_SKILL_D_01, 2);
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
	int myProgress = QuestManager::GetInstance()->GetProgress(myName);

	Character* player = Player::GetInstance()->GetCharacter();


	switch (myProgress)
	{
	case 0: {
		Dialog::EnqueueText(L"�� ���ϰ�ʹ�");
		Dialog::Show();
		//QuestManager::GetInstance()->AddProgress(myName);
		break;
	}
	default:
		break;
	}
}
