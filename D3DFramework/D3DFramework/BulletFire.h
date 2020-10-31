#pragma once
#include "Skill.h"

class BulletFire :
	public Skill
{
public:
	BulletFire();
	virtual ~BulletFire();

public:
	virtual void Active(const Vector3& pos, const Vector3& dir) override;

public:
	static Skill* Create();
};

