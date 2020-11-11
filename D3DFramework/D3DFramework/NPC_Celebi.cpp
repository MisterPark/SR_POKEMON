#include "stdafx.h"
#include "NPC_Celebi.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"

NPC_Celebi::NPC_Celebi()
{
	Initialize();
}

NPC_Celebi::NPC_Celebi(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_Celebi::~NPC_Celebi()
{
	
}

void NPC_Celebi::Initialize()
{
	
	myName = NpcName::CELEBI;
	SetTexture(State::WALK, TextureKey::CELE_WALK_D_02, 3, 2);
	SetTexture(State::IDLE, TextureKey::CELE_WALK_D_01, 3, 1);
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::WALK;
	
	offsetY = 0.7f;
	transform->scale = { 0.5f, 0.5f, 0.5f };

	//stat.money;
	UpdateAnimation();
}

void NPC_Celebi::Update()
{
	NPC::Update();
	UpdateAnimation();
}


NPC_Celebi* NPC_Celebi::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Celebi* newNpc = new NPC_Celebi(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Celebi::OnEvent()
{
	direction = DirFromPlayer(false);
	int myProgress = QuestManager::GetInstance()->GetProgress(myName);

	Character* player = Player::GetInstance()->GetCharacter();


	switch (myProgress)
	{
	case 0: {
		Dialog::EnqueueText(L"���߾�!");
		Dialog::EnqueueText(L"���� �� ĳ���Ǹ� ����غ��ڴ�?");
		Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���.)");
		Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
		Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");
		Dialog::Show();
		QuestManager::GetInstance()->AddProgress(myName);
		break;
	}
	case 1: {
		Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϼ���.)");
		Dialog::EnqueueText(L"(�Ӽ��ڽ��� �̵��ϸ� ���Ͱ� �����˴ϴ�.)");
		Dialog::EnqueueText(L"(��Ŭ������ ����, ��Ŭ������ ��ų�� ��밡���մϴ�.)");
		Dialog::Show();
		break;
	}
	case 2: {
		Dialog::EnqueueText(L"ĳ���Ǹ� ���� ��ƿ� !");
		Dialog::Show();
		QuestManager::GetInstance()->AddProgress(myName);
		break;
	}
	case 3: {
		if (5 > QuestManager::GetInstance()->GetMonsterKill(MonsterType::CATERPIE)) {
			Dialog::EnqueueText(L"ĳ���Ǹ� ���� ��ƿ�! 5������ ");
			Dialog::Show();
		}
		else {
			Dialog::EnqueueText(L"���� !");
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(myName);
		}
		break;
	}
	case 4: {
		Dialog::EnqueueText(L"�� ��Ź�� ����ᱸ�� !");
		Dialog::Show();
	}
	default:
		break;
	}
}
