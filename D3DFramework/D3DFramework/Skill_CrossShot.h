#pragma once
#include "Skill.h"

class Skill_CrossShot :
	public Skill
{
public:
	Skill_CrossShot();
	virtual ~Skill_CrossShot();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

