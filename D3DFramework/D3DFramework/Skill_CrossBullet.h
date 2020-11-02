#pragma once
#include "Skill.h"

class Skill_CrossBullet :
	public Skill
{
public:
	Skill_CrossBullet();
	virtual ~Skill_CrossBullet();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

