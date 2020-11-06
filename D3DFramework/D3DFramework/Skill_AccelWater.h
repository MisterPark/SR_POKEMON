#pragma once
#include "Skill.h"

class Skill_AccelWater :
	public Skill
{
public:
	Skill_AccelWater();
	virtual ~Skill_AccelWater();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

