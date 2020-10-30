#include "stdafx.h"
#include "Monster.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

Monster::Monster()
{
	for (int i = 0; i < 3; i++)
	{
		Frame[i] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		Time[i] = 0.f;
	}
	offsetY = 1.f;

	isAlliance = false;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	//FaceTarget(Camera::GetInstance());
	Character::Update();



	/*Billboard();*/
	/*OnTerrain();*/
}

void Monster::Render()
{

	Character::Render();
}

Vector3 Monster::DirRandom()
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

Vector3 Monster::DirFromPlayer(bool _posY /*= false*/)
{
	Vector3 Dir = playerTrans->position - transform->position;
	if(!_posY)
		Dir.y = 0.f;
	Vector3::Normalize(&Dir);
	return Dir;
}

void Monster::Move(float _moveSpeed2)
{
	transform->position.x += direction.x * moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
}

void Monster::MovePlayerFollow(float _moveSpeed2)
{
	if (playerTrans != nullptr) {
		direction = playerTrans->position - transform->position;
		direction.y = 0.f;
		Vector3::Normalize(&direction);
	}
	transform->position.x += direction.x * moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * _moveSpeed2 * TimeManager::DeltaTime();
}

void Monster::MoveRandomPattern(float _moveTime, int _count, float _moveSpeed2)
{
	Time[0] += TimeManager::DeltaTime();
	Move(_moveSpeed2);

	if (Time[0] >= _moveTime) {
		Time[0] = 0;
		if (Frame[0] >= _count - 1) {
			Frame[0] = 0;
			state = State::READY;
		}
		else {
			Frame[0] ++;
			direction = DirRandom();
		}
	}
}

void Monster::PlayerSearch(float _range, float _rangeOut)
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	if (g == nullptr) return;
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	disPlayer = sqrt(distX * distX + distZ * distZ);

	if (!isSearch) {

		if (disPlayer < _range) {
			isSearch = true;
			playerTrans = PlayerT;
			state = State::READY;
			Time[0] = 0.f;
			Frame[0] = 0.f;
			return;
		}
	}
	else {
		if (disPlayer > _rangeOut) {
			isSearch = false;
			playerTrans = nullptr;
			state = State::READY;
			Time[0] = 0.f;
			Frame[0] = 0.f;
			return;
		}
	}

}

