#pragma once
#include "Skill.h"

class Skill_XClaw :
	public Skill
{
public:
	Skill_XClaw();
	virtual ~Skill_XClaw();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();

private:
	bool isSpawn;
};

