#pragma once
#include "Skill.h"
class Skill_IceBullet2 :
	public Skill
{
public:
	Skill_IceBullet2();
	virtual ~Skill_IceBullet2();

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

