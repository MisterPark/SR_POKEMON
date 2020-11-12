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
	SpawnInRandomPos();

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
	SetIsMoving(false);
	direction = DirFromPlayer(false);
	Event eventNPC = QuestManager::GetInstance()->GetEvent();

	Character* player = Player::GetInstance()->GetCharacter();

	if (eventNPC == Event::EVENT_END)
		return;
	int myProgress = QuestManager::GetInstance()->GetProgress(eventNPC, myName);
	if (eventNPC == Event::EVENT_TOWN || eventNPC == Event::EVENT_GAME)
	{
		switch (myProgress)
		{
		case 0: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::DITTO) {
				Dialog::Show();
				Dialog::EnqueueText(L"어이! 촌놈.", name, Pokemon::Ditto);
				Dialog::EnqueueText(L"그런 촌스러운 색으로 돌아다니다니 !", name, Pokemon::Ditto);
				Dialog::EnqueueText(L"나한테 말을 걸면 색을 바꿔주지 !", name, Pokemon::Ditto);

				QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			}
			else {
				Dialog::Show();
				Dialog::EnqueueText(L"메타몽이 아니면 저리 가라고 !", name, Pokemon::Ditto);
			}
			break;
		}
		case 1: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::DITTO) {
				Player::GetInstance()->MetamorphosisToDitto();
				Dialog::Show();
				Dialog::EnqueueText(L"어때, 마음에 들어?", name, Pokemon::Ditto);
				Player::GetInstance()->AddDittoColor();
				Player::GetInstance()->GetCharacter()->Initialize();
				Player::GetInstance()->MetamorphoEffect();
			}
			else {
				Dialog::Show();
				Dialog::EnqueueText(L"메타몽 인채로 오라고 ! 이 구닥다리야", name, Pokemon::Ditto);
			}
			break;
		}
		default:
			break;
		}
	}
}