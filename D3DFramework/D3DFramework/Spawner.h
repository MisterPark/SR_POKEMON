#pragma once
#include "GameObject.h"
class Spawner : public GameObject
{
public:
	Spawner();
	Spawner(MonsterType _monsterType, int _radius, float _createDelay);
	virtual ~Spawner();



	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	void CreateMonster(MonsterType _monsterType);
public:
	//����Ÿ��, ������ ����(��Ʈ��),������ ������(�ֱ�)
	static Spawner* Create(MonsterType _monsterType, int _radius, float _createDelay);
	

	MonsterType monsterType;
	int radius;
	float createDelay;
	float createTick;
};

