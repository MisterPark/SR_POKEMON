#pragma once
#include "Bullet.h"
class Bullet_HealBubble :
	public Bullet
{
public:
	Bullet_HealBubble();
	virtual ~Bullet_HealBubble();
	// Character��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void OnCollision(GameObject* target) override;

};

