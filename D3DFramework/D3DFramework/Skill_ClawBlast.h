#pragma once
#include "Skill.h"

class Skill_ClawBlast :
	public Skill
{
public:
	Skill_ClawBlast();
	virtual ~Skill_ClawBlast();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

	virtual void CalcActiveTime() override;

public:
	static Skill* Create();

private:
	bool isDetachCamera;
	bool isSpawn;
};

