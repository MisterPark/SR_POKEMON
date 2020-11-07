#pragma once
#include "Bullet.h"
class Bullet_ReverseHealBubble :
	public Bullet
{
public:
	Bullet_ReverseHealBubble();
	virtual ~Bullet_ReverseHealBubble();
	// Character을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

};

