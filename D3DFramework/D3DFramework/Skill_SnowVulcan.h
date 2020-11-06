#pragma once
#include "Skill.h"
class Skill_SnowVulcan :
	public Skill
{
public:
	Skill_SnowVulcan();
	virtual ~Skill_SnowVulcan();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
};

