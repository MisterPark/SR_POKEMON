#pragma once
#include "SkillName.h"

class Skill abstract
{
public:
	Skill();
	virtual ~Skill();

public:
	virtual void Active(const Vector3& pos, const Vector3& dir) = 0;
};