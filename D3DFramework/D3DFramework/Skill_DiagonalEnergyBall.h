#pragma once
#include "Skill.h"
class Skill_DiagonalEnergyBall :
	public Skill
{
public:
	Skill_DiagonalEnergyBall();
	virtual ~Skill_DiagonalEnergyBall();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
	float delaySound = 0.f;
};

