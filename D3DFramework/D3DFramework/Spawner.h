#pragma once
#include "GameObject.h"
class Spawner : public GameObject
{
public:
	Spawner();
	Spawner(MonsterType _monsterType, int _radius, float _createDelay, int _monsterCreateCount, int _monsterLv = 1);
	virtual ~Spawner();



	// GameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	void CreateMonster(MonsterType _monsterType, int _monsterLv=1);
public:
	//몬스터타입, 나오는 범위(인트형),나오는 딜레이(주기), 나오는 몬스터의 수,몬스터의 레벨(디폴트 = 1)
	static Spawner* Create(MonsterType _monsterType, int _radius, float _createDelay, int _monsterCreateCount, int _monsterLv = 1);


	MonsterType monsterType;
	//스포너의 반지름
	int radius;
	//몬스터 생성주기에 관한 변수
	float createDelay;
	//몬스터 생성주기에 관한 변수
	float createTick;
	//몬스터의 수
	int monsterCount;
	//만들 몬스터의 수
	int monsterCreateCount;
	//몬스터의 레벨
	int monsterLv = 1;
};

