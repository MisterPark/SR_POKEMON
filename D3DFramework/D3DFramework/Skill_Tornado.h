#pragma once
#include "Skill.h"

class Skill_Tornado :
	public Skill
{
public:
	Skill_Tornado();
	virtual ~Skill_Tornado();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

