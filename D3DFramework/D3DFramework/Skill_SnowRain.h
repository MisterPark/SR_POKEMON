#pragma once
#include "Skill.h"
class Skill_SnowRain :
	public Skill
{
public:
	Skill_SnowRain();
	virtual ~Skill_SnowRain();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
	float soundDelay = 0.f;
};

