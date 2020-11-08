#pragma once
#include "Bullet.h"
class Bullet_Synthesis :
	public Bullet
{
public:
	Bullet_Synthesis();
	virtual ~Bullet_Synthesis();
	// Character을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

	float stack;
};

