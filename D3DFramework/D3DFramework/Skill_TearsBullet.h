#pragma once
#include "Skill.h"

class Skill_TearsBullet :
	public Skill
{
public:
	Skill_TearsBullet();
	virtual ~Skill_TearsBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitActiveTime() override;
	virtual void Update() override;
	//virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

