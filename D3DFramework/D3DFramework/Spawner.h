#pragma once
#include "GameObject.h"
class Spawner : public GameObject
{
public:
	Spawner();
	Spawner(MonsterType _monsterType, int _radius, float _createDelay);
	virtual ~Spawner();



	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	void CreateMonster(MonsterType _monsterType);
public:
	//몬스터타입, 나오는 범위(인트형),나오는 딜레이(주기)
	static Spawner* Create(MonsterType _monsterType, int _radius, float _createDelay);
	

	MonsterType monsterType;
	int radius;
	float createDelay;
	float createTick;
};

