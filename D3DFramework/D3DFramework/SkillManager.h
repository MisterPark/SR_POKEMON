#pragma once
#include "Skill.h"

class SkillManager
{
private:
	SkillManager();
	~SkillManager();

public:
	static SkillManager* GetInstance();
	static void Destroy();

public:
	Skill* GetSkill(SkillName skillName);

private:
	static SkillManager* instance;
};

