#pragma once
#include "Skill.h"

class Skill_Meteor :
	public Skill
{
public:
	Skill_Meteor();
	virtual ~Skill_Meteor();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

	virtual void CalcActiveTime() override;

public:
	static Skill* Create();
};

