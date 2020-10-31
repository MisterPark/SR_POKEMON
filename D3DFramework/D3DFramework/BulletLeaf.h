#pragma once
#include "Skill.h"

class BulletLeaf :
	public Skill
{
public:
	BulletLeaf();
	virtual ~BulletLeaf();

public:
	virtual void Active(const Vector3& pos, const Vector3& dir) override;

public:
	static Skill* Create();
};

