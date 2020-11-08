#pragma once
#include "Skill.h"

class Skill_ShellAttack :
	public Skill
{
public:
	Skill_ShellAttack();
	virtual ~Skill_ShellAttack();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

private:
	float rocateX = 1.f;
	float rocateZ = 0.f;
	bool rocateXAdd = false;
	bool rocateZAdd = true;
	float delay = 0.f;
};

