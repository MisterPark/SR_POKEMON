#pragma once
#include "Skill.h"

class Skill_Tornado :
	public Skill
{
public:
	Skill_Tornado();
	virtual ~Skill_Tornado();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

