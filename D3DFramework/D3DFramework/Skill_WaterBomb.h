#pragma once
#include "Skill.h"

class Skill_WaterBomb :
	public Skill
{
public:
	Skill_WaterBomb();
	virtual ~Skill_WaterBomb();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

};

