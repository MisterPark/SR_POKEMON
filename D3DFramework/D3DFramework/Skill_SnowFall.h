#pragma once
#include "Skill.h"
class Skill_SnowFall :
	public Skill
{
public:
	class Skill_SnowFall();
	virtual ~Skill_SnowFall();

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

