#pragma once
#include "Skill.h"

class Skill_BubbleShot :
	public Skill
{
public:
	Skill_BubbleShot();
	virtual ~Skill_BubbleShot();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

