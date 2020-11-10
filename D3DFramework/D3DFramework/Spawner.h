#pragma once
#include "GameObject.h"
class Spawner : public GameObject
{
public:
	Spawner();
	Spawner(MonsterType _monsterType, int _radius, float _createDelay, int _monsterCreateCount, int _monsterLv = 1);
	virtual ~Spawner();



	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	void CreateMonster(MonsterType _monsterType, int _monsterLv=1);
public:
	//����Ÿ��, ������ ����(��Ʈ��),������ ������(�ֱ�), ������ ������ ��,������ ����(����Ʈ = 1)
	static Spawner* Create(MonsterType _monsterType, int _radius, float _createDelay, int _monsterCreateCount, int _monsterLv = 1);


	MonsterType monsterType;
	//�������� ������
	int radius;
	//���� �����ֱ⿡ ���� ����
	float createDelay;
	//���� �����ֱ⿡ ���� ����
	float createTick;
	//������ ��
	int monsterCount;
	//���� ������ ��
	int monsterCreateCount;
	//������ ����
	int monsterLv = 1;
};

