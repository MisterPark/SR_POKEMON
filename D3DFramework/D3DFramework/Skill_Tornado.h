#pragma once
#include "Skill.h"

class Skill_Tornado :
	public Skill
{
public:
	Skill_Tornado();
	virtual ~Skill_Tornado();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

