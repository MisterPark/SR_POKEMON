#pragma once
#include "Skill.h"

class Skill_BubbleBullet :
	public Skill
{
public:
	Skill_BubbleBullet();
	virtual ~Skill_BubbleBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

