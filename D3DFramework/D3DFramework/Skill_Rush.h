#pragma once
#include "Skill.h"

class Skill_Rush :
	public Skill
{
public:
	Skill_Rush();
	virtual ~Skill_Rush();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;
	//virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

