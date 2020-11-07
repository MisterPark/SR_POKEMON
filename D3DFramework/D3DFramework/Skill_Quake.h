#pragma once
#include "Skill.h"
class Skill_Quake :
	public Skill
{
public:
	class Skill_Quake();
	virtual ~Skill_Quake();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
	Vector3 bulletDir;


	int Frame[5];
	float patternTime;
};

