#pragma once
#include "Skill.h"

class Skill_WebShot :
	public Skill
{
public:
	Skill_WebShot();
	virtual ~Skill_WebShot();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

