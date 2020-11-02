#pragma once
#include "Skill.h"

class Skill_TearsBullet :
	public Skill
{
public:
	Skill_TearsBullet();
	virtual ~Skill_TearsBullet();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

