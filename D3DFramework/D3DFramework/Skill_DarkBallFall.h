#pragma once
#include "Skill.h"
class Skill_DarkBallFall :
	public Skill
{
public:
	Skill_DarkBallFall();
	virtual ~Skill_DarkBallFall();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

private:
	float delay = 0.f;
	float delaySound = 0.f;
};

