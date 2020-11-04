#pragma once
#include "Skill.h"

class Skill_CrossBullet :
	public Skill
{
public:
	Skill_CrossBullet();
	virtual ~Skill_CrossBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

