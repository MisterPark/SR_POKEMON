#pragma once
#include "Skill.h"

class Skill_XBullet :
	public Skill
{
public:
	Skill_XBullet();
	virtual ~Skill_XBullet();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

