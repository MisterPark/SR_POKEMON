#pragma once
#include "Bullet.h"
class Bullet_Synthesis :
	public Bullet
{
public:
	Bullet_Synthesis();
	virtual ~Bullet_Synthesis();
	// Character��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

	float stack;
};

