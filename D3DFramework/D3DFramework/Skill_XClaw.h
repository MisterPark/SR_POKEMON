#pragma once
#include "Skill.h"

class Skill_XClaw :
	public Skill
{
public:
	Skill_XClaw();
	virtual ~Skill_XClaw();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

private:
	bool isSpawn;
};

