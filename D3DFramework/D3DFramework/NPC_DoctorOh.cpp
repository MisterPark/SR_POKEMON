#include "stdafx.h"
#include "AllNPC.h"
#include "AllItems.h"
NPC_DoctorOh::NPC_DoctorOh()
{
	Initialize();
}

NPC_DoctorOh::NPC_DoctorOh(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_DoctorOh::~NPC_DoctorOh()
{

}

void NPC_DoctorOh::Initialize()
{

	name = L"오박사";
	transform->scale = { 0.3f,0.3f, 0.3f };
	offsetY = 1.2f;
	anim->SetSprite(TextureKey::NPC_DOCTOR_OH, TextureKey::NPC_DOCTOR_OH);
	animation = false;


}

void NPC_DoctorOh::Update()
{
	NPC::Update();
	SetIsMoving(false);
}


NPC_DoctorOh* NPC_DoctorOh::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_DoctorOh* newNpc = new NPC_DoctorOh(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_DoctorOh::OnEvent()
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

			Dialog::EnqueueText(L"(세레비를 찾아가…)", name, Pokemon::None);
			Dialog::EnqueueText(L"(앗…!)", name, Pokemon::None);
			Dialog::EnqueueText(L"(들키고 말았구나……)", name, Pokemon::None);
			Dialog::EnqueueText(L"(속여서 미안하니 지원을 주는 아이템을 주마……)", name, Pokemon::None);
			Dialog::Show();
			Dialog::SetEndEvent(ExpPotion);
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::DOCTOR_OH);

			break;
		}
		case 1: {

			Dialog::EnqueueText(L"화이팅 하거라", name, Pokemon::None);
			Dialog::Show();


			break;
		}
		default:
			break;
		}
	}
}

void NPC_DoctorOh::ExpPotion()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Item_ExpPotion* expPotion = (Item_ExpPotion*)ObjectManager::GetInstance()->CreateObject<Item_ExpPotion>();
			expPotion->transform->position = { 43.f-i,0.f,9.f+j };
			
		}
	}
}

