#pragma once
#include "Skill.h"

class Skill_LeafBullet :
	public Skill
{
public:
	Skill_LeafBullet();
	virtual ~Skill_LeafBullet();

public:
	virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

