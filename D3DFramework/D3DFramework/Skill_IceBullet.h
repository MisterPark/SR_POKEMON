#pragma once
#include "Skill.h"
class Skill_IceBullet :
	public Skill
{
public:
	Skill_IceBullet();
	virtual ~Skill_IceBullet();

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

