#include "stdafx.h"
#include "NPC_Squirtle.h"
#include "Terrain.h"
#include "Environment.h"
#include "Rectangle.h"
#include "Effect.h"
#include "QuestManager.h"
#include "Dialog.h"
#include "AllItems.h"
#include "AllNPC.h"
NPC_Squirtle::NPC_Squirtle()
{
	Initialize();
}

NPC_Squirtle::NPC_Squirtle(const Vector3& pos, bool onCenterDir, const Vector3& dir)
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

NPC_Squirtle::~NPC_Squirtle()
{

}

void NPC_Squirtle::Initialize()
{
	if (0 == QuestManager::GetInstance()->GetEvolution(NpcName::SQUIRTLE)) {
		name = L"꼬부기";
		myName = NpcName::SQUIRTLE;
		SetTexture(State::IDLE, TextureKey::PW01_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PW01_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PW01_ATTACK_D_01, 3);
		SetTexture(State::SKILL, TextureKey::PW01_SKILL_D_01, 1);
	}
	else if (1 == QuestManager::GetInstance()->GetEvolution(NpcName::SQUIRTLE)) {
		name = L"어니부기";
		myName = NpcName::SQUIRTLE;
		SetTexture(State::IDLE, TextureKey::PW02_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PW02_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PW02_ATTACK_D_01, 2);
		SetTexture(State::SKILL, TextureKey::PW02_SKILL_D_01, 1);
	}
	else {
		name = L"거북왕";
		myName = NpcName::SQUIRTLE;
		SetTexture(State::IDLE, TextureKey::PW03_WALK_D_01, 3, 1);
		SetTexture(State::WALK, TextureKey::PW03_WALK_D_02, 3, 2);
		SetTexture(State::ATTACK, TextureKey::PW03_ATTACK_D_01, 1);
		SetTexture(State::SKILL, TextureKey::PW03_SKILL_D_01, 1);
	}
	anim->SetLoop(true);
	anim->SetDelay(0.35f);
	state = State::IDLE;

	offsetY = 0.13f;
	transform->scale = { 0.2f, 0.2f, 0.2f };
	SpawnInRandomPos();

	//stat.money;
	UpdateAnimation();
}

void NPC_Squirtle::Update()
{
	NPC::Update();
	
}


NPC_Squirtle* NPC_Squirtle::Create(const Vector3& pos, bool onCenterDir, const Vector3& dir/* = Vector3{ 24.f, 0.f, 24.f }*/)
{
	NPC_Squirtle* newNpc = new NPC_Squirtle(pos, onCenterDir, dir);
	return newNpc;
}

void NPC_Squirtle::OnEvent()
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

			Dialog::EnqueueText(L"무슨 일이야?", name, Pokemon::Squirtle);
			Dialog::Show();
			//QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"어서와!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"너의 변신 능력은 적에게도 사용할 수 있어!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"바로 사냥을 통해서 말이지……!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"시험삼아…… 저기 저 캐터피를 잡아봐!", name, Pokemon::Squirtle);
			Dialog::SetEndEvent(SummonCaterpie);
			Dialog::Show();
			PlayerInfoPanel::SetQuestMessage(L"캐터피 처치");
			QuestManager::GetInstance()->SetMonsterKill(MonsterType::CATERPIE, 0);
			QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);

			break;
		}
		case 2: {
			//의도적 공백 텍스트 넣으면 터집니다.
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"대단해…!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"하지만 동의가 없는 몬스터로의 변신은\n제한시간이 '5초' 라는 것을 명심해!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"그리고 한번 변신을 하게 되면 저장된 변신몬스터가 사라지지…!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"이제 널 숲으로 보내도 될 것 같아……!", name, Pokemon::Squirtle);
			Dialog::EnqueueText(L"건투를 빌어!", name, Pokemon::Squirtle);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(QuestManager::GetInstance()->GetEvent(), NpcName::SQUIRTLE);
			break;
		}
		case 4: {
			//의도적 공백 텍스트 넣으면 터집니다.
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
			if (Inventory::GetItemCount(ItemType::STONE_OF_WATER) >= 1)
			{

				Dialog::EnqueueText(L"진화의 돌을 찾았구나!", name, Pokemon::Squirtle);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_WATER, 1);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::SQUIRTLE)
			{

				Dialog::EnqueueText(L"건투를 빌어!", name, Pokemon::Squirtle);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::SQUIRTLE)
			{

				Dialog::EnqueueText(L"내 힘을 빌려줄게!", name, Pokemon::Squirtle);
				Dialog::SetEndEvent(MetatoSquirtle);
				Dialog::Show();
			}
			break;
		}
		case 1: {

			Dialog::EnqueueText(L"좋았어!", name, Pokemon::Wartortle);
			Dialog::EnqueueText(L"어니부기 나가신다!", name, Pokemon::Wartortle);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 2: {
			if (Inventory::GetItemCount(ItemType::STONE_OF_WATER) >= 5)
			{

				Dialog::EnqueueText(L"오우! 진화의돌 5개!", name, Pokemon::Wartortle);
				Dialog::EnqueueText(L"땡큐! 땡큐!", name, Pokemon::Wartortle);
				Dialog::SetEndEvent(Evolution);
				Dialog::Show();
				Inventory::RemoveItem(ItemType::STONE_OF_WATER, 5);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::MINISQUIRTLE);
				QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			}
			else if (Player::GetInstance()->GetCharacter()->type == TYPE::WARTORTLE)
			{

				Dialog::EnqueueText(L"화이팅하자고!.", name, Pokemon::Wartortle);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::WARTORTLE)
			{

				Dialog::EnqueueText(L"변! 신!.", name, Pokemon::Wartortle);
				Dialog::SetEndEvent(MetatoWartortle);
				Dialog::Show();
			}
			break;
		}
		case 3: {

			Dialog::EnqueueText(L"나를…….", name, Pokemon::Blastoise);
			Dialog::EnqueueText(L"거북들의 왕이라 불러다오!", name, Pokemon::Blastoise);
			Dialog::Show();
			QuestManager::GetInstance()->AddProgress(eventNPC, NpcName::SQUIRTLE);
			break;
		}
		case 4: {
			if (Player::GetInstance()->GetCharacter()->type == TYPE::BLASTOISE)
			{

				Dialog::EnqueueText(L"어서 가자고!", name, Pokemon::Blastoise);
				Dialog::Show();
			}
			else if (Player::GetInstance()->GetCharacter()->type != TYPE::BLASTOISE)
			{

				Dialog::EnqueueText(L"변신이다!", name, Pokemon::Blastoise);
				Dialog::SetEndEvent(MetatoBlastoise);
				Dialog::Show();
			}
			break;
		}
		default:
			break;
		}
	}
}

void NPC_Squirtle::MetatoSquirtle()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::SQUIRTLE, Pokemon::Squirtle);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Squirtle::MetatoWartortle()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::WARTORTLE, Pokemon::Wartortle);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Squirtle::MetatoBlastoise()
{
	Player::GetInstance()->ChangeNextPokemon(TYPE::BLASTOISE, Pokemon::Blastoise);
	Player::GetInstance()->PermanentMetamorphosis();
}

void NPC_Squirtle::SummonCaterpie()
{
	Spawner* spawner = Spawner::Create(MonsterType::CATERPIE, 5.f, 0.5f, 1, 2);
	spawner->transform->position = { 25.f,0.f,22.f };
	ObjectManager::AddObject(spawner);
	
}

void NPC_Squirtle::Evolution()
{
	QuestManager::GetInstance()->AddEvolution(NpcName::SQUIRTLE);
	dynamic_cast<NPC_Squirtle*>(ObjectManager::GetInstance()->FindObject<NPC_Squirtle>())->Initialize();
	dynamic_cast<NPC_Squirtle*>(ObjectManager::GetInstance()->FindObject<NPC_Squirtle>())->MetamorphoEffect();
}
