#pragma once
#include "Bullet.h"
class Bullet_Ice2 :
	public Bullet
{
public:
	Bullet_Ice2();
	virtual ~Bullet_Ice2();
	// Character을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

};

