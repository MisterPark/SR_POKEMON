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
	virtual void InitActiveTime() override;
	virtual void Update() override;
	//virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

