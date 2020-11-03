#pragma once
#include "Skill.h"

class Skill_FireBullet :
	public Skill
{
public:
	Skill_FireBullet();
	virtual ~Skill_FireBullet();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

