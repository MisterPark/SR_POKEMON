#pragma once
#include "Skill.h"
class Skill_FireBomb :
	public Skill
{
public:
	Skill_FireBomb();
	virtual ~Skill_FireBomb();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

};

