#pragma once
#include "Skill.h"
class Skill_FireXCrossBomb :
	public Skill
{
public:
	Skill_FireXCrossBomb();
	virtual ~Skill_FireXCrossBomb();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

};

