#pragma once
#include "Character.h"
class Bullet :
	public Character
{
public:
	Bullet();
	virtual ~Bullet();
	// Character을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	
protected:
	float Time[3];  // 프레임(시간) 재는용도
	Vector3 MoveDir;
};

