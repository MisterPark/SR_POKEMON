#pragma once
#include "Bullet.h"
class Bullet_FireWallWave :
	public Bullet
{
public:
	Bullet_FireWallWave();
	virtual ~Bullet_FireWallWave();
	// Character��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

	int stack;
};

