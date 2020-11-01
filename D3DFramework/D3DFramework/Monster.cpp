#include "stdafx.h"
#include "Monster.h"
#include "Plane.h"
#include "Rectangle.h"
#include "Terrain.h"
#include "Environment.h"

Monster::Monster()
{
	//monsterAI = (MonsterAI*)AddComponent<MonsterAI>(L"MonsterAi");
	Initialize();
}

Monster::~Monster()
{
	Release();
}

void Monster::Initialize()
{
	//offsetY = 1.f;

	//isAlliance = false;
}

void Monster::Update()
{
	//if (nullptr == monster) return;
	
	//Character::Update();
	monsterAI.Update();
	
}


void Monster::Release()
{
}


