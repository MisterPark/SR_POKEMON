#include "stdafx.h"
#include "MonsterAI.h"
#include "Bullet_Water.h"
#include "Bullet_Tornado.h"
#include "Bullet_Web.h"
#include "Bullet_Poision.h"
#include "Bullet_Bubble.h"
MonsterAI::MonsterAI()
{
	for (int i = 0; i < 3; i++)
	{
		Frame[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		Time[i] = 0.f;
	}
	for (int i = 0; i < 4; i++)
	{
		searchRange[i] = 0.f;
	}
	
}

MonsterAI::MonsterAI(const MonsterAI& rhs)
{
}

MonsterAI::~MonsterAI()
{
}

void MonsterAI::Update()
{
	Pattern();
	LimitPosition();
}

MonsterAI* MonsterAI::Clone()
{
	return nullptr;
}

Vector3 MonsterAI::DirRandom()
{
	Vector3 Dir = { 0.f, 0.f, 0.f };
	while (Dir.x == 0 && Dir.z == 0) {
		Dir.x = -5.f + Random::Value(10) * 1.f;
		Dir.y = 0.f;
		Dir.z = -5.f + Random::Value(10) * 1.f;
	}
	Vector3::Normalize(&Dir);
	return Dir;
}
void MonsterAI::SpawnInRandomPos()
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	if (c->spawner == nullptr) return;

	int dist = 0;
	while (dist < 2) {
		dist = Random::Value(c->spawner->radius);
	}
	float degree = Random::Value(360);
	float Radian = D3DXToRadian(degree);

	Vector3 vecSpawnPosition;
	vecSpawnPosition.x = dist;
	vecSpawnPosition.z = 0;

	float movePositionX = cosf(Radian) * vecSpawnPosition.x - sinf(Radian) * vecSpawnPosition.z + c->spawner->transform->position.x;
	float movePositionZ = sinf(Radian) * vecSpawnPosition.x + cosf(Radian) * vecSpawnPosition.z + c->spawner->transform->position.z;

	spawnInPos = { movePositionX, 0.f, movePositionZ };
	c->direction = spawnInPos - c->transform->position;
	c->direction.y = 0.f;
	Vector3::Normalize(&c->direction);

	return;
}
Vector3 MonsterAI::DirFromPlayer(bool _posY /*= false*/)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return Vector3{ 0.f, 0.f, 0.f };

	Vector3 Dir = playerTrans->position - c->transform->position;
	if (!_posY)
		Dir.y = 0.f;
	Vector3::Normalize(&Dir);
	return Dir;
}
void MonsterAI::Move(float _moveSpeed2)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	c->transform->position.x += c->direction.x * c->stat.moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	c->transform->position.z += c->direction.z * c->stat.moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
}
void MonsterAI::MovePlayerFollow(float _moveSpeed2)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	if (playerTrans != nullptr) {
		c->direction = playerTrans->position - c->transform->position;
		c->direction.y = 0.f;
		Vector3::Normalize(&c->direction);
	}

	float distX = playerTrans->position.x - c->transform->position.x;
	float distZ = playerTrans->position.z - c->transform->position.z;

	float dis = sqrt(distX * distX + distZ * distZ);

	if (dis > 0.2f) {
		c->transform->position.x += c->direction.x * c->stat.moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
		c->transform->position.z += c->direction.z * c->stat.moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	}
}
void MonsterAI::MoveRandomPattern(float _moveSpeed2)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	float distX = spawnInPos.x - c->transform->position.x;
	float distZ = spawnInPos.z - c->transform->position.z;

	float dis = sqrt(distX * distX + distZ * distZ);
	if (dis < 0.2f) {
		SpawnInRandomPos();
	}
	
	c->transform->position.x += c->direction.x * c->stat.moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	c->transform->position.z += c->direction.z * c->stat.moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
}

void MonsterAI::PlayerSearch(float _range, float _rangeOut)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	//GameObject* g = ObjectManager::GetInstance()->GetNearestObject<Character>((GameObject*)this, Character::IsNotAlliance);
	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	if (g == nullptr) return;
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - c->transform->position.x;
	float distZ = PlayerT->position.z - c->transform->position.z;

	disPlayer = sqrt(distX * distX + distZ * distZ);

	if (!isSearch) {

		if (disPlayer < _range) {
			isSearch = true;
			playerTrans = PlayerT;
			c->state = State::READY;
			Time[0] = 0.f;
			Frame[0] = 0.f;
			return;
		}
	}
	else {
		if (disPlayer > _rangeOut) {
			isSearch = false;
			playerTrans = nullptr;
			c->state = State::READY;
			Time[0] = 0.f;
			Frame[0] = 0.f;
			return;
		}
	}

}
void MonsterAI::LimitPosition()
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	if (c->transform->position.x < 3) {
		c->direction.x *= -1.f;
		c->transform->position.x = 3;
	}
	else if (c->transform->position.x > dfTERRAIN_WIDTH - 3) {
		c->direction.x *= -1.f;
		c->transform->position.x = dfTERRAIN_WIDTH - 3;
	}

	if (c->transform->position.z < 3) {
		c->direction.z *= -1.f;
		c->transform->position.z = 3;
	}
	else if (c->transform->position.z > dfTERRAIN_HEIGHT - 3) {
		c->direction.z *= -1.f;
		c->transform->position.z = dfTERRAIN_HEIGHT - 3;
	}
}
#pragma region SetType
void MonsterAI::SetType(MonsterType _type)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;
	type = _type;
	switch (type)
	{
	case MonsterType::BULBASAUR:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::LVYSAUR:
		break;
	case MonsterType::VENUSAUR:
		break;
	case MonsterType::SQUIRTLE:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::WARTORTLE:
		break;
	case MonsterType::BLASTOISE:
		break;
	case MonsterType::CHARMANDER:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::CHARMELEON:
		break;
	case MonsterType::CHARIZARD:
		break;
	case MonsterType::CATERPIE:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::METAPOD:
		SetPatternRange(1, 1);
		break;
	case MonsterType::ODDISH:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::GLOOM:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::VILEPLUME:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::SCYTHER:
		SetPatternRange(1, 1);
		searchRange[0] = 10.f;
		searchRange[1] = 8.f;
		searchRange[3] = 20.f;
		break;
	case MonsterType::BUTTERFREE:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 4.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::PSYDUCK:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::GOLDUCK:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::POLIWAG:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::POLIWHIRL:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::POLIWRATH:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 4.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::JYNX:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::SUICUNE:
		SetPatternRange(1, 1);
		searchRange[0] = 8.f;
		searchRange[1] = 5.f;
		searchRange[3] = 30.f;
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
		SetPatternRange(1, 1);
		searchRange[0] = 48.f;
		searchRange[1] = 2.f;
		searchRange[3] = 30.f;
		break;
	case MonsterType::END:
		break;

	default:
		break;
	}
}
#pragma endregion
#pragma region Pattern
void MonsterAI::Pattern()
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지
	PlayerSearch(searchRange[0], searchRange[3]);


	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
	if (isSearch) {

		/////////////////////////////////////////////////////////// 패턴 Ready
		if (c->state == State::READY) {
			readyPattern = true;
			c->state = (State)Random::Range(beginPattern, endPattern);
		}

		/////////////////////////////////////////////////////////// 패턴 Update
		if (c->state == State::IDLE) {
			MonsterIdle();
		}
		else if (c->state == State::WALK) {
			MonsterWalk();
		}
		else if (c->state == State::ATTACK) {
			MonsterAttack();
		}
		else if (c->state == State::SKILL) {
			MonsterSkill();
		}
		else if (c->state == State::SKILL2) {
			MonsterSkill2();
		}

	}



	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
	else {

		/////////////////////////////////////////////////////////// 패턴 Ready
		if (c->state == State::READY) {
			readyPattern = true;
			c->state = (State)Random::Range(beginPattern, endPattern);
		}

		/////////////////////////////////////////////////////////// 패턴 Update
		if (c->state == State::IDLE) {
			MonsterIdle();
		}
		else if (c->state == State::WALK) {
			MonsterWalk();
		}
		else if (c->state == State::ATTACK) {
			MonsterAttack();
		}
		else if (c->state == State::SKILL) {
			MonsterSkill();
		}
		else if (c->state == State::SKILL2) {
			MonsterSkill2();
		}
	}

}
#pragma endregion
#pragma region MonsterIdle
void MonsterAI::MonsterIdle() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE		Idle
	if (isSearch) {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			break;
		case MonsterType::LVYSAUR:
			break;
		case MonsterType::VENUSAUR:
			break;
		case MonsterType::SQUIRTLE:
			break;
		case MonsterType::WARTORTLE:
			break;
		case MonsterType::BLASTOISE:
			break;
		case MonsterType::CHARMANDER:
			break;
		case MonsterType::CHARMELEON:
			break;
		case MonsterType::CHARIZARD:
			break;
		case MonsterType::CATERPIE:
			break;
		case MonsterType::METAPOD:
			break;
		case MonsterType::ODDISH:
			break;
		case MonsterType::GLOOM:
			break;
		case MonsterType::POLIWHIRL:
			break;
		case MonsterType::VILEPLUME:
			break;
		case MonsterType::SCYTHER:
			break;
		case MonsterType::BUTTERFREE:
			break;
		case MonsterType::PSYDUCK:
			break;
		case MonsterType::GOLDUCK:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[1] > 0.f) {
					Time[1] -= TimeManager::DeltaTime();
				}
				else {
					Time[1] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
				c->state = State::WALK; //WALK 와 다른점
			}
			break;
		case MonsterType::POLIWAG:
			break;
		case MonsterType::POLIWRATH:
			break;
		case MonsterType::JYNX:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[1] > 0.f) {
					Time[1] -= TimeManager::DeltaTime();
				}
				else {
					Time[1] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
				c->state = State::WALK; //WALK 와 다른점
			}
			break;
		case MonsterType::SUICUNE:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			Time[3] -= TimeManager::DeltaTime();
			if (Time[3] < 0.f) {
				c->state = State::SKILL2;
				readyPattern = true;
			}
			else {
				Time[2] -= TimeManager::DeltaTime();
				if (disPlayer > searchRange[1]) {
					MovePlayerFollow();
					c->state = State::WALK;
				}
				else if (Time[2] < 0) {
					Time[2] = 1.2f;
					if (Frame[1] == 0) {
						c->state = State::ATTACK;
						readyPattern = true;
						Frame[1] = 1;
					}
					else if (Frame[1] == 1) {
						c->state = State::SKILL;
						readyPattern = true;
						Frame[1] = 0;
					}
				}
			}
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
	}
	


	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE		Idle
	else {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			break;
		case MonsterType::LVYSAUR:
			break;
		case MonsterType::VENUSAUR:
			break;
		case MonsterType::SQUIRTLE:
			break;
		case MonsterType::WARTORTLE:
			break;
		case MonsterType::BLASTOISE:
			break;
		case MonsterType::CHARMANDER:
			break;
		case MonsterType::CHARMELEON:
			break;
		case MonsterType::CHARIZARD:
			break;
		case MonsterType::CATERPIE:
			break;
		case MonsterType::METAPOD:
			break;
		case MonsterType::ODDISH:
			break;
		case MonsterType::GLOOM:
			break;
		case MonsterType::VILEPLUME:
			break;
		case MonsterType::SCYTHER:
			break;
		case MonsterType::BUTTERFREE:
			break;
		case MonsterType::PSYDUCK:
			break;
		case MonsterType::GOLDUCK:
			break;
		case MonsterType::POLIWAG:
			break;
		case MonsterType::POLIWHIRL:
			break;
		case MonsterType::POLIWRATH:
			break;
		case MonsterType::JYNX:
			break;
		case MonsterType::SUICUNE:
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
	}
}
#pragma endregion
#pragma region MonsterWalk
void MonsterAI::MonsterWalk() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE		Walk
	if (isSearch) {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}

			if (disPlayer < searchRange[1]) {
				if (Time[2] > 0.f) {
					Time[2] -= TimeManager::DeltaTime();
					//MovePlayerFollow();
				}
				else {
					c->state = State::ATTACK;
					Time[2] = 0.f;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}

			break;
		case MonsterType::LVYSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}

			if (disPlayer < searchRange[1]) {
				if (Time[2] > 0.f) {
					Time[2] -= TimeManager::DeltaTime();
					//MovePlayerFollow();
				}
				else {
					c->state = State::ATTACK;
					Time[2] = 0.f;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}

			break;
		case MonsterType::CHARMELEON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}

			if (disPlayer < searchRange[1]) {
				if (Time[2] > 0.f) {
					Time[2] -= TimeManager::DeltaTime();
					//MovePlayerFollow();
				}
				else {
					c->state = State::ATTACK;
					Time[2] = 0.f;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}

			break;
		case MonsterType::METAPOD:
			if (readyPattern) {

				readyPattern = false;
			}

			break;
		case MonsterType::ODDISH:
			if (readyPattern) {

				readyPattern = false;
			}
			MovePlayerFollow();

			break;
		case MonsterType::GLOOM:
			if (readyPattern) {

				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[4] > 0.f) {
					Time[4] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[4] = 0.f;
					c->state = State::ATTACK;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}

			break;
		case MonsterType::VILEPLUME:
			if (readyPattern) {

				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[4] > 0.f) {
					Time[4] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[4] = 0.f;
					c->state = State::ATTACK;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			
			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[2] > 0.f) {
					Time[2] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[2] = 0.f;
					c->state = State::SKILL2;
					readyPattern = true;
				}
			}
			else {
				if (Time[3] > 0.f) {
					Time[3] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					c->state = State::SKILL;
					readyPattern = true;
				}
			}
			
			break;
		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}

			if (disPlayer < searchRange[1]) {
				c->state = State::ATTACK;
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::PSYDUCK:
			if (readyPattern) {

				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[4] > 0.f) {
					Time[4] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[4] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::GOLDUCK:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[1] > 0.f) {
					Time[1] -= TimeManager::DeltaTime();
					c->state = State::IDLE;  //IDLE 와 다른점
				}
				else {
					Time[1] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::POLIWAG:
			if (readyPattern) {

				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[4] > 0.f) {
					Time[4] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[4] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;

		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[1] > 0.f) {
					Time[1] -= TimeManager::DeltaTime();
				}
				else {
					Time[1] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {

				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[4] > 0.f) {
					Time[4] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[4] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::JYNX:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[1] > 0.f) {
					Time[1] -= TimeManager::DeltaTime();
					c->state = State::IDLE;  //IDLE 와 다른점
				}
				else {
					Time[1] = 0.f;
					c->state = State::ATTACK;
					readyPattern = true;
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::SUICUNE:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			Time[3] -= TimeManager::DeltaTime();
			if (Time[3] < 0.f) {
				c->state = State::SKILL2;
				readyPattern = true;
			}
			else {
				Time[2] -= TimeManager::DeltaTime();
				if (disPlayer > searchRange[1]) {
					MovePlayerFollow();
				}
				else if (Time[2] < 0) {
					Time[2] = 1.2f;
					if (Frame[1] == 0) {
						c->state = State::ATTACK;
						readyPattern = true;
						Frame[1] = 1;
					}
					else if (Frame[1] == 1) {
						c->state = State::SKILL;
						readyPattern = true;
						Frame[1] = 0;
					}
				}
				else {
					c->state = State::IDLE;
				}
			}
			break;

		case MonsterType::GROWLITHE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ARCANINE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PONYTA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::RAPIDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SLUGMA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::MAGCARGO:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GROUDON:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				readyPattern = false;
			}
			if (disPlayer < searchRange[1]) {
				if (Time[2] > 0.f) {
					Time[2] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					Time[2] = 0.f;
					c->state = State::SKILL2;
					readyPattern = true;
				}
			}
			else {
				if (Time[3] > 0.f) {
					Time[3] -= TimeManager::DeltaTime();
					MovePlayerFollow();
				}
				else {
					c->state = State::SKILL;
					readyPattern = true;
				}
			}

			break;
		case MonsterType::END:
			break;
		default:
			break;
		}
	}

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE		Walk
	else {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::LVYSAUR:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::CHARMELEON:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::METAPOD:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			
			break;
		case MonsterType::ODDISH:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::VILEPLUME:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			
			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {
				c->anim->SetDelay(0.2f);
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			
			break;
		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();
			
			break;
		case MonsterType::PSYDUCK:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::GOLDUCK:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::POLIWAG:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::JYNX:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::SUICUNE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::GROWLITHE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::ARCANINE:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::PONYTA:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::RAPIDISH:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::SLUGMA:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::MAGCARGO:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::GROUDON:
			if (readyPattern) {
				SpawnInRandomPos();
				readyPattern = false;
			}
			MoveRandomPattern();

			break;
		case MonsterType::END:
			break;
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region MonsterAttack
void MonsterAI::MonsterAttack() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE		Attack
	if (isSearch) {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::LVYSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMELEON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				if (disPlayer < searchRange[1]) {
					c->state = State::ATTACK;
					c->anim->SetDelay(0.3f);
				}
				else {//if (disPlayer > 10.f)
					c->state = State::WALK;
					c->anim->SetDelay(0.3f);
				}
				readyPattern = false;
			}

			Time[1] += TimeManager::DeltaTime();

			if (Time[1] >= 0.25f) {
				Time[0] = 0;
				Frame[1]++;
				if (Frame[1] == 1) {
					c->direction = DirFromPlayer();
					c->Attack(c->direction, 0);
				}
				else if (Frame[1] == 2) {
					c->anim->SetDelay(0.2f);	
					Time[1] = 0.f;
					Frame[1] = 0.f;
					c->state = State::READY;
					Time[2] = 2.5f;
				}
			}

			break;
		case MonsterType::METAPOD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ODDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
				c->anim->SetDelay(0.3f);
				SpawnInRandomPos();
				readyPattern = false;
			}

			Time[1] += TimeManager::DeltaTime();
			if (Frame[3] == 0 && Time[1] >= 0.3f) {

				Frame[3] = 1;
				if (Frame[1] % 1 == 0)
					c->Attack(c->direction, 0);
			}
			if (Time[1] >= 0.6f) {
				Time[1] = 0.f;
				Frame[1]++;
				Frame[3] = 0;
				if (Frame[1] == 3) {
					Frame[1] = 0;
					c->anim->SetDelay(0.2f);
					c->state = State::WALK;
					Time[4] = 3.f; //쿨타임
				}
			}

		case MonsterType::VILEPLUME:
			if (readyPattern) {
				c->anim->SetDelay(0.3f);
				SpawnInRandomPos();
				readyPattern = false;
			}
			
			Time[1] += TimeManager::DeltaTime();
			if (Frame[3] == 0 && Time[1] >= 0.3f) {

				Frame[3] = 1;
				if (Frame[1] % 2 == 1)
					c->Attack(c->direction, 0);
				else
					c->Attack(c->direction, 1);
			}
			if (Time[1] >= 0.6f) {
				Time[1] = 0.f;
				Frame[1]++;
				Frame[3] = 0;
				if (Frame[1] == 3) {
					Frame[1] = 0;
					c->anim->SetDelay(0.2f);
					c->state = State::WALK;
					Time[4] = 3.f; //쿨타임
				}
			}
			
			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {
				c->anim->SetDelay(1.f);
				readyPattern = false;
			}

			break;
		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				if (disPlayer < searchRange[1]) {
					c->state = State::ATTACK;
					c->anim->SetDelay(0.5f);
				}
				else {//if (disPlayer > 10.f)
					c->state = State::WALK;
					c->anim->SetDelay(0.5f);
				}
				readyPattern = false;
			}
			
			Time[1] += TimeManager::DeltaTime();

			if (Time[1] >= 0.9f) {
				Time[0] = 0;
				Frame[1]++;
				if (Frame[1] == 1) {
					c->direction = DirFromPlayer(true);
					c->Attack(c->direction, 0);
				}
				else if (Frame[1] == 2) {
					c->anim->SetDelay(0.2f);
					Time[1] = 0.f;
					Frame[1] = 0.f;
					c->state = State::READY;
				}
			}
			
			break;
		case MonsterType::PSYDUCK:
			if (readyPattern) {
				if (disPlayer < searchRange[1]) {
					c->state = State::ATTACK;
					c->anim->SetDelay(0.3f);
				}
				else {//if (disPlayer > 10.f)
					c->state = State::WALK;
					c->anim->SetDelay(0.3f);
				}
				readyPattern = false;
			}

			Time[1] += TimeManager::DeltaTime();

			if (Time[1] >= 0.75f) {
				Time[0] = 0;
				Frame[1]++;
				if (Frame[1] == 1) {
					Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
					c->direction = DirFromPlayer(true);
					Vector3 bDir = { c->direction.x, c->direction.y + 0.2f, c->direction.z };
					b->SetDir(bDir);
					*(b->transform) = *c->transform;
					b->transform->position.y -= 0.5f;
				}
				else if (Frame[1] == 2) {
					c->anim->SetDelay(0.6f);
					Time[1] = 0.f;
					Frame[1] = 0.f;
					c->state = State::READY;
					Time[2] = 2.5f;
				}
			}
			break;
		case MonsterType::GOLDUCK:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 0);
				Time[4] = 2.2f;
				c->anim->SetDelay(0.6f);
				Time[1] = 1.5f;
			}
			Time[4] -= TimeManager::DeltaTime();
			if (Time[4] < 0.f) {
				c->state = State::READY;
				Time[4] = 0.f;
			}
			break;
		case MonsterType::POLIWAG:
			if (readyPattern) {
				if (disPlayer < searchRange[1]) {
					c->state = State::ATTACK;
					c->anim->SetDelay(0.3f);
				}
				else {//if (disPlayer > 10.f)
					c->state = State::WALK;
					c->anim->SetDelay(0.3f);
				}
				readyPattern = false;
			}

			Time[1] += TimeManager::DeltaTime();

			if (Time[1] >= 1.0f) {
				Time[0] = 0;
				Frame[1]++;
				if (Frame[1] == 1) {
					Bullet_Bubble* b = dynamic_cast<Bullet_Bubble*>(ObjectManager::GetInstance()->CreateObject<Bullet_Bubble>());
					c->direction = DirFromPlayer(true);
					Vector3 bDir = { c->direction.x, c->direction.y + 0.2f, c->direction.z };
					b->SetDir(bDir);
					*(b->transform) = *c->transform;
					b->transform->position.y -= 0.5f;
				}
				else if (Frame[1] == 2) {
					c->anim->SetDelay(0.2f);
					Time[1] = 0.f;
					Frame[1] = 0.f;
					c->state = State::READY;
					Time[2] = 2.5f;
				}
			}
			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				c->Attack(c->direction, 0);
				c->direction = DirFromPlayer();
				Time[4] = 2.f;
				c->anim->SetDelay(0.4f);
				readyPattern = false;
			}
			Time[4] -= TimeManager::DeltaTime();
			if (Time[4] < 0.f) {
				c->state = State::READY;
				Time[4] = 0.f;
				Time[1] = 0.f; //Attack쿨타임
			}
			break;
			//if (readyPattern) {
			//	if (disPlayer < searchRange[1]) {
			//		c->state = State::ATTACK;
			//		c->anim->SetDelay(0.4f);
			//		/*c->anim->SetDelay(false);
			//		c->anim->SetTick(0.f);*/
			//	}
			//	else {//if (disPlayer > 10.f)
			//		c->state = State::WALK;
			//		c->anim->SetDelay(0.3f);
			//	}
			//	readyPattern = false;
			//}

			//Time[1] += TimeManager::DeltaTime();

			//if (Time[1] >= 0.25f) {
			//	Time[0] = 0;
			//	Frame[1]++;
			//	if (Frame[1] == 1) {
			//		c->direction = DirFromPlayer();
			//		c->Attack(c->direction, 0);
			//	}
			//	else if (Frame[1] == 2) {
			//		c->anim->SetDelay(0.2f);
			//		Time[1] = 0.f;
			//		Frame[1] = 0.f;
			//		c->state = State::READY;
			//		Time[2] = 2.5f;
			//	}
			//}

		case MonsterType::POLIWRATH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::JYNX:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 0);
				Time[4] = 3.5f;
				c->anim->SetDelay(1.f);
				Time[1] = 3.f;
			}
			Time[4] -= TimeManager::DeltaTime();
			if (Time[4] < 0.f) {
				c->state = State::READY;
				Time[4] = 0.f;
			}
			break;
		case MonsterType::SUICUNE:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 0);
				Time[4] = 4.f;
				c->anim->SetDelay(0.7f);
			}
			Time[4] -= TimeManager::DeltaTime();
			if (Time[4] < 0.f) {
				c->state = State::READY;
			}
			break;

		case MonsterType::GROWLITHE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ARCANINE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PONYTA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::RAPIDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SLUGMA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::MAGCARGO:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GROUDON:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 0);
				Time[3] = 4.f;
				c->anim->SetDelay(0.7f);
			}
			Time[3] -= TimeManager::DeltaTime();
			if (Time[3] < 0.f) {
				c->state = State::READY;
				Time[3] = 0.f;
			}
			break;

		case MonsterType::END:
			break;
		default:
			break;
		}
	}

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE		Attack

	else {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::LVYSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMELEON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::METAPOD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ODDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VILEPLUME:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SCYTHER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PSYDUCK:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GOLDUCK:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::POLIWAG:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::JYNX:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 0);
				Time[4] = 6.f;
				c->anim->SetDelay(1.f);
			}
			Time[4] -= TimeManager::DeltaTime();
			if (Time[4] < 0.f) {
				c->state = State::READY;
				Time[4] = 0.f;
			}
			break;

		case MonsterType::SUICUNE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GROWLITHE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ARCANINE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PONYTA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::RAPIDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SLUGMA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::MAGCARGO:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GROUDON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::END:
			break;
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region MonsterSkill
void MonsterAI::MonsterSkill() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE		Skill
	if (isSearch) {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::LVYSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMELEON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::METAPOD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ODDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::VILEPLUME:
			if (readyPattern) {
				readyPattern = false;
			}

			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {
				c->anim->SetDelay(1.5f);
				c->direction = DirFromPlayer();
				c->Attack(c->direction, 0);
					
				readyPattern = false;
			}
			Time[2] += TimeManager::DeltaTime();
			if (1.5f < Time[2]) {
				Time[2] = 0;
				c->state = State::READY;
				Time[3] = 0.5f; // 쿨타임
			}
			//if (1.5f < Time[1]) {
			//	MovePlayerFollow(15.f);
			//	if (1.65f < Time[1]) {
			//		c->state = State::READY;
			//		Time[1] = 0;
			//		//
			//		for (int j = -2; j < 3; j++)
			//		{
			//			for (int i = -2; i < 3; i++)
			//			{
			//				Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
			//				Vector3 Dir2 = { c->direction.x + j * 0.8f, 0.f, c->direction.z + i * 0.8f };
			//				Dir2.Normalized();
			//				b->SetDir(Dir2);
			//				*(b->transform) = *c->transform;
			//				b->transform->position.y -= 0.5f;
			//				b->transform->scale.x = 0.7f;
			//				b->transform->scale.y = 0.7f;
			//				b->transform->scale.z = 0.7f;
			//			}
			//		}
			//		c->anim->SetDelay(0.1f);
			//	}
			//}
			break;

		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PSYDUCK:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GOLDUCK:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::POLIWAG:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::JYNX:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SUICUNE:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 1);
				Time[4] = 5.f;
				c->anim->SetDelay(0.8f);
			}
			Time[4] -= TimeManager::DeltaTime();
			if (Time[4] < 0.f) {
				c->state = State::READY;
			}
			break;

		case MonsterType::GROWLITHE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ARCANINE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PONYTA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::RAPIDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SLUGMA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::MAGCARGO:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GROUDON:
			if (readyPattern) {
				c->anim->SetDelay(1.5f);
				c->direction = DirFromPlayer();
				c->Attack(c->direction, 0);

				readyPattern = false;
			}
			Time[2] += TimeManager::DeltaTime();
			if (1.5f < Time[2]) {
				Time[2] = 0;
				c->state = State::READY;
				Time[3] = 0.5f; // 쿨타임
			}

		case MonsterType::END:
			break;
		default:
			break;
		}
	}

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE		Skill
	else {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::LVYSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMELEON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::METAPOD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ODDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VILEPLUME:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SCYTHER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PSYDUCK:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GOLDUCK:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::POLIWAG:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::JYNX:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SUICUNE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::GROWLITHE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ARCANINE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PONYTA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::RAPIDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::SLUGMA:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::MAGCARGO:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::GROUDON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::END:
			break;

		default:
			break;
		}
	}
}
#pragma endregion
#pragma region MonsterSkill2
void MonsterAI::MonsterSkill2() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE		Skill2
	if (isSearch) {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::LVYSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VENUSAUR:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SQUIRTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::WARTORTLE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::BLASTOISE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMANDER:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARMELEON:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CHARIZARD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::CATERPIE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::METAPOD:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::ODDISH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::VILEPLUME:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::SCYTHER:
			if (readyPattern) {
				c->anim->SetDelay(1.f);
				readyPattern = false;
			}

			Time[1] += TimeManager::DeltaTime();
			if (Time[1] > 0.8f) {
				Time[1] = 0;
				Frame[1]++;
				if (Frame[1] == 1) {
					c->Attack(c->direction, 1);

				}
				else if (Frame[1] == 2) {
					c->state = State::READY;
					c->anim->SetDelay(0.1f);
					Frame[1] = 0;
					Frame[2]++;
					Time[2] = 3.f; //쿨타임
					
				}
			}
			
			break;
		case MonsterType::BUTTERFREE:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::PSYDUCK:
			break;

		case MonsterType::GOLDUCK:
			break;

		case MonsterType::POLIWAG:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
				readyPattern = false;
			}
			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {
				readyPattern = false;
			}
			break;

		case MonsterType::JYNX:
			break;

		case MonsterType::SUICUNE:
			if (readyPattern) {
				readyPattern = false;
				c->Attack(c->direction, 2); //몬스터의 3번째 스킬
				Time[4] = 3.f;				//모션 고정할 시간 (State)
				c->anim->SetDelay(0.6f);	//애니메이션 셋딜레이
			}
			Time[4] -= TimeManager::DeltaTime(); //Update 영역 모션고정할시간 계속빼줌
			if (Time[4] < 0.f) {			//위에서 설정한 3초가 나면
				c->state = State::READY;	//State를 READY 로 설정
				Time[3] = 4.f;				//현재 스킬 즉 패턴 Skill2 의 쿨타임으로 활용
			}
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
	}

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE		Skill2
	else {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			if (readyPattern) {
			}
			break;
		case MonsterType::LVYSAUR:
			if (readyPattern) {
			}
			break;
		case MonsterType::VENUSAUR:
			if (readyPattern) {
			}
			break;
		case MonsterType::SQUIRTLE:
			if (readyPattern) {
			}
			break;
		case MonsterType::WARTORTLE:
			if (readyPattern) {
			}
			break;
		case MonsterType::BLASTOISE:
			if (readyPattern) {
			}
			break;
		case MonsterType::CHARMANDER:
			if (readyPattern) {
			}
			break;
		case MonsterType::CHARMELEON:
			if (readyPattern) {
			}
			break;
		case MonsterType::CHARIZARD:
			if (readyPattern) {
			}
			break;
		case MonsterType::CATERPIE:
			if (readyPattern) {
			}
			break;
		case MonsterType::METAPOD:
			if (readyPattern) {
			}
			break;
		case MonsterType::ODDISH:
			if (readyPattern) {
			}
			break;
		case MonsterType::GLOOM:
			if (readyPattern) {
			}
			break;

		case MonsterType::VILEPLUME:
			if (readyPattern) {
			}
			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {
			}
			break;
		case MonsterType::BUTTERFREE:
			if (readyPattern) {
			}
			break;
		case MonsterType::PSYDUCK:
			if (readyPattern) {
			}
			break;
		case MonsterType::GOLDUCK:
			if (readyPattern) {
			}
			break;
		case MonsterType::POLIWAG:
			if (readyPattern) {
			}
			break;
		case MonsterType::POLIWHIRL:
			if (readyPattern) {
			}
			break;
		case MonsterType::POLIWRATH:
			if (readyPattern) {
			}
			break;
		case MonsterType::JYNX:
			if (readyPattern) {
			}
			break;
		case MonsterType::SUICUNE:
			if (readyPattern) {
			}
			break;
		case MonsterType::GROWLITHE:
			if (readyPattern) {
			}
			break;
		case MonsterType::ARCANINE:
			if (readyPattern) {
			}
			break;
		case MonsterType::PONYTA:
			if (readyPattern) {
			}
			break;
		case MonsterType::RAPIDISH:
			if (readyPattern) {
			}
			break;
		case MonsterType::SLUGMA:
			if (readyPattern) {
			}
			break;
		case MonsterType::MAGCARGO:
			if (readyPattern) {
			}
			break;
		case MonsterType::GROUDON:
			if (readyPattern) {
			}
			break;
		case MonsterType::END:
			break;
		default:
			break;
		}
	}
}
#pragma endregion