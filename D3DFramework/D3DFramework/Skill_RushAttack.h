#pragma once
#include "Skill.h"

class Skill_RushAttack :
	public Skill
{
public:
	Skill_RushAttack();
	virtual ~Skill_RushAttack();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

