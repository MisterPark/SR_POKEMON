#pragma once
#include "Skill.h"

class Skill_WaterBullet :
	public Skill
{
public:
	Skill_WaterBullet();
	virtual ~Skill_WaterBullet();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

