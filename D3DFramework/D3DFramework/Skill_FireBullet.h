#pragma once
#include "Skill.h"

class Skill_FireBullet :
	public Skill
{
public:
	Skill_FireBullet();
	virtual ~Skill_FireBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
};

