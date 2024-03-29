#pragma once
#include "Skill.h"
class Skill_FireWallWave :
	public Skill
{
public:
	class Skill_FireWallWave();
	virtual ~Skill_FireWallWave();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
	int Frame[5];
	float patternTime;
	float soundTime;
	float effectDelay = 0.f;
};

