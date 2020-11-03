#include "stdafx.h"
#include "Skill.h"

Skill::Skill()
{
	SkillManager::GetInstance()->AddSkillToList(this);
}

Skill::~Skill()
{
	SkillManager::GetInstance()->DeleteSkillFromList(this);
}

void Skill::Active(Character * _character)
{
	if (!isActive)
	{
		character = _character;
		isActive = true;
	}
}

void Skill::CalcActiveTime()
{
	activeTime -= TimeManager::DeltaTime();
}

void Skill::SetNoneActive()
{
	InitActiveTime();
	isActive = false;
}
