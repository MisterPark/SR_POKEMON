#pragma once
#include "Skill.h"

class Skill_Blaze :
	public Skill
{
public:
	Skill_Blaze();
	virtual ~Skill_Blaze();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

