#pragma once
#include "Skill.h"

class Skill_FireBullet :
	public Skill
{
public:
	Skill_FireBullet();
	virtual ~Skill_FireBullet();

public:
	virtual void Active(const Vector3& pos, const Vector3& dir) override;

public:
	static Skill* Create();
};

