#include "stdafx.h"
#include "MonsterAI.h"
#include "Bullet_Water.h"
#include "Bullet_Tornado.h"
#include "Bullet_Web.h"

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

	c->transform->position.x += c->direction.x * c->moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	c->transform->position.z += c->direction.z * c->moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
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
	c->transform->position.x += c->direction.x * c->moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	c->transform->position.z += c->direction.z * c->moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
}

void MonsterAI::MoveRandomPattern(float _moveTime, int _count, float _moveSpeed2)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	Time[0] += TimeManager::DeltaTime();
	Move(_moveSpeed2);

	if (Time[0] >= _moveTime) {
		Time[0] = 0;
		if (Frame[0] >= _count - 1) {
			Frame[0] = 0;
			c->state = State::READY;
		}
		else {
			Frame[0] ++;
			c->direction = DirRandom();
		}
	}
}

void MonsterAI::PlayerSearch(float _range, float _rangeOut)
{
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

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

void MonsterAI::SetType(MonsterType _type)
{
	type = _type;
	switch (type)
	{
	case MonsterType::BULBASAUR:
		break;
	case MonsterType::LVYSAUR:
		break;
	case MonsterType::VENUSAUR:
		break;
	case MonsterType::CATERPIE:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 6.f;
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
	case MonsterType::VILEPLUME:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::SCYTHER:
		SetPatternRange(1, 1);
		searchRange[0] = 10.f;
		searchRange[1] = 7.f;
		searchRange[3] = 20.f;
		break;
	case MonsterType::BUTTERFREE:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 6.f;
		searchRange[3] = 10.f;
		break;
	case MonsterType::PSYDUCK:
		SetPatternRange(1, 1);
		searchRange[0] = 6.f;
		searchRange[1] = 3.f;
		searchRange[3] = 10.f;
		break;
		break;
	case MonsterType::GOLDUCK:
		break;
	case MonsterType::POLIWAG:
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

//////////////////////////////////////////////////////////////////////////////////////////////// Idle

void MonsterAI::MonsterIdle() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
	if (isSearch) {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			break;
		case MonsterType::LVYSAUR:
			break;
		case MonsterType::VENUSAUR:
			break;
		case MonsterType::CATERPIE:
			break;
		case MonsterType::METAPOD:
			break;
		case MonsterType::ODDISH:
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

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
	else {
		switch (type)
		{
		case MonsterType::BULBASAUR:
			break;
		case MonsterType::LVYSAUR:
			break;
		case MonsterType::VENUSAUR:
			break;
		case MonsterType::CATERPIE:
			break;
		case MonsterType::METAPOD:
			break;
		case MonsterType::ODDISH:
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

//////////////////////////////////////////////////////////////////////////////////////////////// Walk

void MonsterAI::MonsterWalk() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
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
		case MonsterType::CATERPIE:
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
				c->state = State::SKILL;
				readyPattern = true;
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
				}
			}
			else {				//if (disPlayer > 10.f)
				MovePlayerFollow();
			}
			break;
		case MonsterType::GOLDUCK:
			break;
		case MonsterType::POLIWAG:
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

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
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
		case MonsterType::CATERPIE:
			if (readyPattern) {

				readyPattern = false;
			}
			MoveRandomPattern(1.5f, 3);

			break;
		case MonsterType::METAPOD:
			if (readyPattern) {

				readyPattern = false;
			}
			
			MoveRandomPattern(1.5f, 3);
			
			break;
		case MonsterType::ODDISH:
			if (readyPattern) {

				readyPattern = false;
			}
			
			MoveRandomPattern(1.5f, 3);
			
			break;
		case MonsterType::VILEPLUME:
			if (readyPattern) {

				readyPattern = false;
			}
			
			MoveRandomPattern(1.5f, 3);
			
			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {

				readyPattern = false;
			}
			
			MoveRandomPattern(1.5f, 1);
			
			break;
		case MonsterType::BUTTERFREE:
			if (readyPattern) {

				readyPattern = false;
			}
			MoveRandomPattern(1.5f, 3);
			
			break;
		case MonsterType::PSYDUCK:
			if (readyPattern) {

				readyPattern = false;
			}

			MoveRandomPattern(1.5f, 3);
			break;
		case MonsterType::GOLDUCK:
			break;
		case MonsterType::POLIWAG:
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

//////////////////////////////////////////////////////////////////////////////////////////////// Attack

void MonsterAI::MonsterAttack() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
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
		case MonsterType::CATERPIE:
			if (readyPattern) {
				if (disPlayer < searchRange[1]) {
					c->state = State::ATTACK;
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
					Bullet_Web* b = dynamic_cast<Bullet_Web*>(ObjectManager::GetInstance()->CreateObject<Bullet_Web>());
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
		case MonsterType::VILEPLUME:
			if (readyPattern) {
				c->anim->SetDelay(0.3f);
				readyPattern = false;
			}
			
			Time[1] += TimeManager::DeltaTime();
			if (Frame[3] == 0 && Time[1] >= 0.3f) {

				Frame[3] = 1;
				if (Frame[1] % 2 == 1)
					CrossBullet();
				else
					XBullet();
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
					Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
					c->direction = DirFromPlayer(true);
					Vector3 bDir = { c->direction.x, c->direction.y + 0.1f, c->direction.z };
					b->SetDir(bDir);
					b->transform->position = c->transform->position;
					b->transform->position.y -= 0.5f;
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
				c->anim->SetDelay(0.3f);
				readyPattern = false;
			}

			Time[1] += TimeManager::DeltaTime();
			if (Frame[3] == 0 && Time[1] >= 0.3f) {

				Frame[3] = 1;
				if (Frame[1] % 2 == 1)
					CrossBullet();
				else
					XBullet();
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
		case MonsterType::GOLDUCK:
			break;
		case MonsterType::POLIWAG:
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

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
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

//////////////////////////////////////////////////////////////////////////////////////////////// Skill

void MonsterAI::MonsterSkill() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
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
		case MonsterType::VILEPLUME:
			if (readyPattern) {

				readyPattern = false;
			}

			break;
		case MonsterType::SCYTHER:
			if (readyPattern) {
				c->anim->SetDelay(1.5f);
				readyPattern = false;
			}
			
			Time[1] += TimeManager::DeltaTime();
			if (1.5f < Time[1]) {
				MovePlayerFollow(15.f);
				if (1.65f < Time[1]) {
					c->state = State::READY;
					Time[1] = 0;
					//
					for (int j = -2; j < 3; j++)
					{
						for (int i = -2; i < 3; i++)
						{
							Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
							Vector3 Dir2 = { c->direction.x + j * 0.8f, 0.f, c->direction.z + i * 0.8f };
							Dir2.Normalized();
							b->SetDir(Dir2);
							*(b->transform) = *c->transform;
							b->transform->position.y -= 0.5f;
							b->transform->scale.x = 0.7f;
							b->transform->scale.y = 0.7f;
							b->transform->scale.z = 0.7f;
						}
					}
					c->anim->SetDelay(0.1f);
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

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
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
			break;
		case MonsterType::GOLDUCK:
			break;
		case MonsterType::POLIWAG:
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

//////////////////////////////////////////////////////////////////////////////////////////////// Skill2

void MonsterAI::MonsterSkill2() {
	Character* c = dynamic_cast<Character*>(gameObject);
	if (c == nullptr) return;

	/////////////////////////////////////////////////////////// 플레이어 탐지 TRUE
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
					Bullet_Tornado* b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
					Vector3 Dir2 = { -1.f, 0.f, 1.f };
					Dir2.Normalized();
					b->SetDir(Dir2);
					b->transform->position = c->transform->position;

					b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
					Dir2 = { 1.f, 0.f, 1.f };
					Dir2.Normalized();
					b->SetDir(Dir2);
					b->transform->position = c->transform->position;

					b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
					Dir2 = { -1.f, 0.f, -1.f };
					Dir2.Normalized();
					b->SetDir(Dir2);
					b->transform->position = c->transform->position;

					b = dynamic_cast<Bullet_Tornado*>(ObjectManager::GetInstance()->CreateObject<Bullet_Tornado>());
					Dir2 = { 1.f, 0.f, -1.f };
					Dir2.Normalized();
					b->SetDir(Dir2);
					b->transform->position = c->transform->position;
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

	/////////////////////////////////////////////////////////// 플레이어 탐지 FALSE
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
			break;
		case MonsterType::GOLDUCK:
			break;
		case MonsterType::POLIWAG:
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

void MonsterAI::CrossBullet()
{
	float R = 1.f;

	Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Vector3 Dir2 = { 0.f,0.f,0.f };
	Dir2.z -= R;
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;
}

void MonsterAI::XBullet()
{
	float R = 1.f;

	Bullet_Water* b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Vector3 Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z -= R;
	Dir2.Normalized();
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x -= R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z -= R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;

	b = dynamic_cast<Bullet_Water*>(ObjectManager::GetInstance()->CreateObject<Bullet_Water>());
	Dir2 = { 0.f,0.f,0.f };
	Dir2.x += R;
	Dir2.z += R;
	Dir2.Normalized();
	D3DXVec3Normalize(&Dir2, &Dir2);
	b->SetDir(Dir2);
	*(b->transform) = *gameObject->transform;
	b->moveSpeed = 0.5f;
	b->isAlliance = false;
}
