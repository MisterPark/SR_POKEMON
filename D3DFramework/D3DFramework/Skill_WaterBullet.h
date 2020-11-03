#pragma once
#include "Skill.h"

class Skill_WaterBullet :
	public Skill
{
public:
	Skill_WaterBullet();
	virtual ~Skill_WaterBullet();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

