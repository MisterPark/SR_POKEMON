#pragma once
#include "Skill.h"

class Skill_WebBullet :
	public Skill
{
public:
	Skill_WebBullet();
	virtual ~Skill_WebBullet();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitActiveTime() override;
	virtual void Update() override;
	//virtual void Active(const Character* character) override;

public:
	static Skill* Create();
};

