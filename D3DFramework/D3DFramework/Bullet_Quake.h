#pragma once
#include "Bullet.h"
class Bullet_Quake :
	public Bullet
{
public:
	Bullet_Quake();
	virtual ~Bullet_Quake();
	// Character을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

	int stack;
};

