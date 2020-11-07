#pragma once
#include "Skill.h"
class Skill_ReverseHealBubble :
	public Skill
{
public:
	class Skill_ReverseHealBubble();
	virtual ~Skill_ReverseHealBubble();

public:
	// Skill을(를) 통해 상속됨
	virtual void InitCoolTime() override;
	virtual void InitActiveTime() override;
	virtual void Update() override;

public:
	static Skill* Create();
private:
	float delay = 0.f;
	Vector3 bulletDir;
	bool create = false;
};

