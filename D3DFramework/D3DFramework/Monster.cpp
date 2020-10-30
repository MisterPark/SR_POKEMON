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

Vector3 Monster::RandomDir()
{
	Vector3 Dir = {0.f, 0.f, 0.f};
	while (Dir.x == 0 && Dir.z == 0) {
		Dir.x = -5.f + Random::Value(10) * 1.f;
		Dir.y = 0.f;
		Dir.z = -5.f + Random::Value(10) * 1.f;
	}
	Vector3::Normalize(&Dir);
	return Dir;
}

void Monster::Move()
{
	transform->position.x += direction.x * moveSpeed * TimeManager::DeltaTime();
	transform->position.z += direction.z * moveSpeed * TimeManager::DeltaTime();
}

void Monster::PlayerSearch(float _range, float _rangeOut)
{
	GameObject* g = ObjectManager::GetInstance()->FindObject<Character>();
	Transform* PlayerT = g->transform;

	float distX = PlayerT->position.x - transform->position.x;
	float distZ = PlayerT->position.z - transform->position.z;

	float Dist = sqrt(distX * distX + distZ * distZ);

	if (!isSearch) {

		if (Dist < _range) {
			isSearch = true;
			PlayerTrans = PlayerT;
			return;
		}
	}
	else {
		if (Dist > _rangeOut) {
			isSearch = false;
			PlayerTrans = nullptr;
			return;
		}
	}
	
}

