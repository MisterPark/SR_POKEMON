#include "stdafx.h"
#include "Spawner.h"

#include "Charmander.h"

#include "Bulbasaur.h"
#include "Ivysaur.h"
#include "Venusaur.h"

#include "Caterpie.h"
#include "Metapod.h"
#include "Butterfree.h"
#include "Oddish.h"
#include "Vileplume.h"
#include "Scyther.h"


#include "Psyduck.h"
#include "Golduck.h"
#include "Poliwag.h"
#include "Poliwrath.h"
#include "Jynx.h"
#include "Suicune.h"

Spawner::Spawner()
{
	Initialize();
}

Spawner::Spawner(MonsterType _monsterType, int _radius, float _createDelay)
{
	monsterType = _monsterType;
	radius = _radius;
	createDelay = _createDelay;
	Initialize();
}



Spawner::~Spawner()
{
	Release();
}

void Spawner::Initialize()
{

}

void Spawner::Release()
{
}

void Spawner::Update()
{
	CreateMonster(monsterType);
	GameObject::Update();
}

void Spawner::CreateMonster(MonsterType _monsterType)
{
	createTick += TimeManager::DeltaTime();
	if (createTick > createDelay)
	{

		int dist = Random::Value(radius);
		float degree = Random::Value(360);
		float Radian = D3DXToRadian(degree);

		Vector3 vecSpawnPosition;
		vecSpawnPosition.x = dist;
		vecSpawnPosition.z = 0;

		float spawnPositionX = cosf(Radian) * vecSpawnPosition.x - sinf(Radian) * vecSpawnPosition.z + transform->position.x;
		float spawnPositionZ = sinf(Radian) * vecSpawnPosition.x + cosf(Radian) * vecSpawnPosition.z + transform->position.z;

		switch (_monsterType)
		{
		case MonsterType::BULBASAUR:
		{
			Bulbasaur* monsterCharacter = Bulbasaur::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::BULBASAUR);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::LVYSAUR:
			break;
		case MonsterType::VENUSAUR:
			break;
		case MonsterType::CATERPIE:
		{
			Caterpie* monsterCharacter = Caterpie::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::CATERPIE);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::METAPOD:
		{
			Metapod* monsterCharacter = Metapod::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::METAPOD);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::ODDISH:
		{
			Oddish* monsterCharacter = Oddish::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::ODDISH);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::VILEPLUME:
		{
			Vileplume* monsterCharacter = Vileplume::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::VILEPLUME);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::SCYTHER:
		{
			Scyther* monsterCharacter = Scyther::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(1.f, 1.f, 1.f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::SCYTHER);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::BUTTERFREE:
		{
			Butterfree* monsterCharacter = Butterfree::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::BUTTERFREE);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::SQUIRTLE:
			break;
		case MonsterType::WARTORTLE:
			break;
		case MonsterType::BLASTOISE:
			break;
		case MonsterType::PSYDUCK:
		{
			Psyduck* monsterCharacter = Psyduck::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::PSYDUCK);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::GOLDUCK:
		{
			Golduck* monsterCharacter = Golduck::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::GOLDUCK);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::POLIWAG:
		{
			Poliwag* monsterCharacter = Poliwag::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::POLIWAG);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::POLIWRATH:
		{
			Poliwrath* monsterCharacter = Poliwrath::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::POLIWRATH);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::JYNX:
		{
			Jynx* monsterCharacter = Jynx::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::JYNX);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::SUICUNE:
		{
			Suicune* monsterCharacter = Suicune::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(1.f, 1.f, 1.f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::SUICUNE);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::CHARMANDER:
		{
			Charmander* monsterCharacter = Charmander::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.5f, 0.5f, 0.5f), Vector3(0.f, 0.f, 1.f));
			monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
			monsterCharacter->monsterAI->SetType(MonsterType::CHARMANDER);
			ObjectManager::AddObject(monsterCharacter);
			CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
			break;
		}
		case MonsterType::CHARMELEON:
			break;
		case MonsterType::CHARIZARD:
			break;
		case MonsterType::GROWLITHE:
			break;
		case MonsterType::ARCANINE:
			break;
		case MonsterType::PONYTA:
			break;
		case MonsterType::RAPIDISH:
			break;
		case MonsterType::SLUGMA:
			break;
		case MonsterType::MAGCARGO:
			break;
		case MonsterType::GROUDON:
			break;
		case MonsterType::END:
			break;

		default:
			break;
		}
		createTick = 0;
	}

}

Spawner* Spawner::Create(MonsterType _monsterType, int _radius, float _createDelay)
{
	Spawner* newSpawner = new Spawner(_monsterType, _radius, _createDelay);
	return newSpawner;
}
