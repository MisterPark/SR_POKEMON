#pragma once
#include "Bullet.h"
class Bullet_FireBlast :
	public Bullet
{
public:
	Bullet_FireBlast();
	virtual ~Bullet_FireBlast();
	// Character��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

	int stack;
};

