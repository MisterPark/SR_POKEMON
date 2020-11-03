#pragma once
#include "Skill.h"

class Skill_TearsBullet :
	public Skill
{
public:
	Skill_TearsBullet();
	virtual ~Skill_TearsBullet();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

