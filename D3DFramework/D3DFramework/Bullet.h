#pragma once
#include "Character.h"
class Bullet :
	public Character
{
public:
	Bullet();
	virtual ~Bullet();
	// Character��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	
protected:
	float Time[3];  // ������(�ð�) ��¿뵵
	Vector3 MoveDir;
};

