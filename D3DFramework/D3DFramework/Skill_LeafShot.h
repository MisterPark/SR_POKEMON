#pragma once
#include "Skill.h"

class Skill_LeafShot :
	public Skill
{
public:
	Skill_LeafShot();
	virtual ~Skill_LeafShot();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

