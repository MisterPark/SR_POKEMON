#pragma once
#include "Skill.h"

class Skill_WaterFlow :
	public Skill
{
public:
	Skill_WaterFlow();
	virtual ~Skill_WaterFlow();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

