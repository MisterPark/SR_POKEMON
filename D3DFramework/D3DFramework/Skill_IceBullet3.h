#pragma once
#include "Skill.h"
class Skill_IceBullet3 :
	public Skill
{
public:
	class Skill_IceBullet3();
	virtual ~Skill_IceBullet3();

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

