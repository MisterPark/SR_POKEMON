#pragma once
#include "Skill.h"

class Skill_LeafBullet :
	public Skill
{
public:
	Skill_LeafBullet();
	virtual ~Skill_LeafBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

