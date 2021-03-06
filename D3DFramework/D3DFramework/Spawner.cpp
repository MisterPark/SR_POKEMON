#include "stdafx.h"
#include "AllCharacters.h"

Spawner::Spawner()
{
	Initialize();
}

Spawner::Spawner(MonsterType _monsterType, float _radius, float _createDelay, int _monsterCreateCount, int _monsterLv)
{
	monsterType = _monsterType;
	radius = _radius;
	createDelay = _createDelay;
	monsterCreateCount = _monsterCreateCount;
	monsterLv = _monsterLv;
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
	CreateMonster(monsterType,monsterLv);
	GameObject::Update();
}

void Spawner::CreateMonster(MonsterType _monsterType,int _monsterLv)
{
	if (monsterCreateCount > 0)
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
				Bulbasaur* monsterCharacter = Bulbasaur::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::BULBASAUR);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::IVYSAUR:
				break;
			case MonsterType::VENUSAUR:
				break;
			case MonsterType::CATERPIE:
			{
				Caterpie* monsterCharacter = Caterpie::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::CATERPIE);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::METAPOD:
			{
				Metapod* monsterCharacter = Metapod::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::METAPOD);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::ODDISH:
			{
				Oddish* monsterCharacter = Oddish::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::ODDISH);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::GLOOM:
			{
				Gloom* monsterCharacter = Gloom::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::GLOOM);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::VILEPLUME:
			{
				Vileplume* monsterCharacter = Vileplume::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::VILEPLUME);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::SCYTHER:
			{
				Scyther* monsterCharacter = Scyther::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::SCYTHER);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::BUTTERFREE:
			{
				Butterfree* monsterCharacter = Butterfree::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::BUTTERFREE);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
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
				Psyduck* monsterCharacter = Psyduck::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::PSYDUCK);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::GOLDUCK:
			{
				Golduck* monsterCharacter = Golduck::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::GOLDUCK);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::POLIWAG:
			{
				Poliwag* monsterCharacter = Poliwag::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::POLIWAG);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::POLIWHIRL:
			{
				Poliwhirl* monsterCharacter = Poliwhirl::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::POLIWHIRL);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::POLIWRATH:
			{
				Poliwrath* monsterCharacter = Poliwrath::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::POLIWRATH);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::JYNX:
			{
				Jynx* monsterCharacter = Jynx::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::JYNX);
				monsterCharacter->spawner = this;
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::SUICUNE:
			{
				Suicune* monsterCharacter = Suicune::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::SUICUNE);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::CHARMANDER:
			{
				Charmander* monsterCharacter = Charmander::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::CHARMANDER);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::CHARMELEON:
				break;
			case MonsterType::CHARIZARD:
				break;
			case MonsterType::GROWLITHE:
			{
				Growlithe* monsterCharacter = Growlithe::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::GROWLITHE);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::ARCANINE:
			{
				Arcanine* monsterCharacter = Arcanine::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::ARCANINE);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::PONYTA:
			{
				Ponyta* monsterCharacter = Ponyta::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::PONYTA);
				monsterCharacter->spawner = this;
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::RAPIDASH:
			{
				Rapidash* monsterCharacter = Rapidash::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::RAPIDASH);
				monsterCharacter->spawner = this;
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::SLUGMA:
			{
				Slugma* monsterCharacter = Slugma::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::SLUGMA);
				monsterCharacter->spawner = this;
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::MAGCARGO:
			{
				Magcargo* monsterCharacter = Magcargo::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::MAGCARGO);
				monsterCharacter->spawner = this;
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::GROUDON:
			{

				Groudon* monsterCharacter = Groudon::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ),  Vector3(0.f, 0.f, 1.f),_monsterLv);
				monsterCharacter->offsetY=2.f;
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::GROUDON);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::DARKRAI:
			{

				Darkrai* monsterCharacter = Darkrai::Create(Vector3(spawnPositionX, 0.f, spawnPositionZ), Vector3(0.f, 0.f, 1.f), _monsterLv);
				monsterCharacter->monsterAI = dynamic_cast<MonsterAI*>(monsterCharacter->AddComponent<MonsterAI>(L"MonsterAI"));
				monsterCharacter->monsterAI->SetType(MonsterType::DARKRAI);
				monsterCharacter->spawner = this;
				monsterCharacter->monsterAI->SpawnInRandomPos();
				ObjectManager::AddObject(monsterCharacter);
				CollisionManager::RegisterObject(COLTYPE::ENEMY, monsterCharacter);
				break;
			}
			case MonsterType::END:
				break;

			default:
				break;
			}
			createTick = 0;
			monsterCount++;
			monsterCreateCount--;
		}
	}
	else if (monsterCount==0&&monsterCreateCount == 0)
	{
		Die();
	}
}

Spawner* Spawner::Create(MonsterType _monsterType, float _radius, float _createDelay, int _monsterCreateCount, int _monsterLv)
{
	Spawner* newSpawner = new Spawner(_monsterType, _radius, _createDelay, _monsterCreateCount, _monsterLv);
	return newSpawner;
}
