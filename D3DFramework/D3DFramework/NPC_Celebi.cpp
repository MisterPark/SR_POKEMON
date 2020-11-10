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

NPC_Celebi::NPC_Celebi(const Vector3& pos)
{
	transform->position = pos;
	Initialize();
}

NPC_Celebi::~NPC_Celebi()
{
	CollisionManager::GetInstance()->DisregisterObject(this);
}

void NPC_Celebi::Initialize()
{
	//SetTexture(State::IDLE, TextureKey::COINPOKE_1, 27);
	
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


NPC_Celebi* NPC_Celebi::Create(const Vector3& pos)
{
	NPC_Celebi* newNpc = new NPC_Celebi(pos);
	return newNpc;
}

void NPC_Celebi::OnEvent()
{
	int myProgress = QuestManager::GetInstance()->GetProgress(NpcName::CELEBI);

	Character* player = Player::GetInstance()->GetCharacter();


	switch (myProgress)
	{
	case 0: {
		Dialog::EnqueueText(L"안녕! 난 세레비야");
		Dialog::Show();
		QuestManager::GetInstance()->AddProgress(NpcName::CELEBI);
		break;
	}
	case 1: {
		Dialog::EnqueueText(L"캐터피를 5마리 잡아주겠니?");
		Dialog::Show();
		QuestManager::GetInstance()->AddProgress(NpcName::CELEBI);
		break;
	}
	case 2: {
		Dialog::EnqueueText(L"캐터피를 빨리 잡아와 !");
		Dialog::Show();
		QuestManager::GetInstance()->AddProgress(NpcName::CELEBI);
		break;
	}
	default:
		break;
	}
}

