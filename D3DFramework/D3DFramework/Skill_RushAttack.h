#pragma once
#include "Skill.h"

class Skill_RushAttack :
	public Skill
{
public:
	Skill_RushAttack();
	virtual ~Skill_RushAttack();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitActiveTime() override;
	virtual void Update() override;
	//virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

