#pragma once
#include "Skill.h"

class Skill_WaterBullet :
	public Skill
{
public:
	Skill_WaterBullet();
	virtual ~Skill_WaterBullet();

public:
	virtual void Active(const Vector3& pos, const Vector3& dir) override;

public:
	static Skill* Create();
};

