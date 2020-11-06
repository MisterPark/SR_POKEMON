#pragma once
#include "Skill.h"

class Skill_TearsShot :
	public Skill
{
public:
	Skill_TearsShot();
	virtual ~Skill_TearsShot();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

