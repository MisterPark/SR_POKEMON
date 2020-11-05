#pragma once
#include "Skill.h"
class Skill_HealBubble :
	public Skill
{
public:
	class Skill_HealBubble();
	virtual ~Skill_HealBubble();

public:
	// Skill��(��) ���� ��ӵ�
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
	Vector3 bulletDir;
	bool create=false;
};

