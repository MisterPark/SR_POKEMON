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

	name = L"�νθ�";
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
				Dialog::EnqueueText(L"����! �̳�.", name, Pokemon::Ditto);
				Dialog::EnqueueText(L"�׷� �̽����� ������ ���ƴٴϴٴ� !", name, Pokemon::Ditto);
				Dialog::EnqueueText(L"������ ���� �ɸ� ���� �ٲ����� !", name, Pokemon::Ditto);

				QuestManager::GetInstance()->AddProgress(eventNPC, myName);
			}
			else {
				Dialog::Show();
				Dialog::EnqueueText(L"��Ÿ���� �ƴϸ� ���� ����� !", name, Pokemon::Ditto);
			}
			break;
		}
		case 1: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::DITTO) {
				Player::GetInstance()->MetamorphosisToDitto();
				Dialog::Show();
				Dialog::EnqueueText(L"�, ������ ���?", name, Pokemon::Ditto);
				Player::GetInstance()->AddDittoColor();
				Player::GetInstance()->GetCharacter()->Initialize();
				Player::GetInstance()->MetamorphoEffect();
			}
			else {
				Dialog::Show();
				Dialog::EnqueueText(L"��Ÿ�� ��ä�� ����� ! �� ���ڴٸ���", name, Pokemon::Ditto);
			}
			break;
		}
		default:
			break;
		}
	}
}