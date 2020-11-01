#pragma once
#include "Skill.h"

class Skill_LeafBullet :
	public Skill
{
public:
	Skill_LeafBullet();
	virtual ~Skill_LeafBullet();

public:
	virtual void Active(const Vector3& pos, const Vector3& dir) override;

public:
	static Skill* Create();
};

