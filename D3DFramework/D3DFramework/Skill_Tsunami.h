#pragma once
#include "Skill.h"

class Skill_Tsunami :
	public Skill
{
public:
	Skill_Tsunami();
	virtual ~Skill_Tsunami();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

private:
	float delay = 0.f;
};

