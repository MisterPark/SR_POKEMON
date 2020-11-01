#pragma once
#include "SkillName.h"
#include "Character.h"

class Skill abstract
{
public:
	Skill();
	virtual ~Skill();

public:
	virtual void Active(const Character* character) = 0;
};