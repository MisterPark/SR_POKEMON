#pragma once
#include "Skill.h"
class Skill_SnowCrystal :
	public Skill
{
public:
	Skill_SnowCrystal();
	virtual ~Skill_SnowCrystal();

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

