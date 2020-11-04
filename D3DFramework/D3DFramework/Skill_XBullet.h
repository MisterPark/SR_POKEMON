#pragma once
#include "Skill.h"

class Skill_XBullet :
	public Skill
{
public:
	Skill_XBullet();
	virtual ~Skill_XBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;
	//virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

