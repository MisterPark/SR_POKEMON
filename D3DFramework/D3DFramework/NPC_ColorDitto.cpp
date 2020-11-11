#include "stdafx.h"
#include "NPC_ColorDitto.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"

NPC_ColorDitto::NPC_ColorDitto()
{
	Initialize();
}

NPC_ColorDitto::NPC_ColorDitto(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_ColorDitto::~NPC_ColorDitto()
{

}

void NPC_ColorDitto::Initialize()
{

	name = L"인싸몽";
	myName = NpcName::COLOR_DITTO;
	SetTexture(State::IDLE, TextureKey::DITTOY_WALK_D_01, 3, 1);
	SetTexture(State::WALK, TextureKey::DITTOY_WALK_D_02, 3, 2);
	
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.3f;
	transform->scale = { 0.3f, 0.3f, 0.3f };

	//stat.money;
	UpdateAnimation();
}

void NPC_ColorDitto::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_ColorDitto* NPC_ColorDitto::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_ColorDitto* newNpc = new NPC_ColorDitto(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_ColorDitto::OnEvent()
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
			Dialog::EnqueueText(L"어이! 촌놈.", name, Pokemon::Ditto);
			Dialog::EnqueueText(L"그런 촌스러운 색으로 돌아다니다니 !", name, Pokemon::Ditto);
			Dialog::EnqueueText(L"나한테 말을 걸면 색을 바꿔주지 !", name, Pokemon::Ditto);
			
			QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			break;
		}
		case 1: {
			Player::GetInstance()->MetamorphosisToDitto();
			Dialog::Show();
			Dialog::EnqueueText(L"어때, 마음에 들어?", name, Pokemon::Ditto);
			Player::GetInstance()->AddDittoColor();
			Player::GetInstance()->GetCharacter()->Initialize();
			Player::GetInstance()->MetamorphoEffect();
			break;
		}
		default:
			break;
		}
	}
}