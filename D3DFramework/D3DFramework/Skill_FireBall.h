#pragma once
#include "Skill.h"

class Skill_FireBall :
	public Skill
{
public:
	Skill_FireBall();
	virtual ~Skill_FireBall();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

