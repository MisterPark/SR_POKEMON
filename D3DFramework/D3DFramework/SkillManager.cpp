#include "stdafx.h"
#include "SkillManager.h"
#include "AllSkills.h"

SkillManager* SkillManager::instance = nullptr;

SkillManager::SkillManager()
{
}

SkillManager::~SkillManager()
{
}

SkillManager * SkillManager::GetInstance()
{
	if (nullptr == instance) instance = new SkillManager;
	return instance;
}

void SkillManager::Destroy()
{
	if (nullptr != instance)
	{
		delete instance;
		instance = nullptr;
	}
}

Skill * SkillManager::GetSkill(SkillName skillName)
{
	Skill* newSkill = nullptr;

	switch (skillName)
	{
	case SkillName::LeafBullet:
		newSkill = Skill_LeafBullet::Create();
		break;

	case SkillName::FireBullet:
		newSkill = Skill_FireBullet::Create();
		break;

	case SkillName::WaterBullet:
		newSkill = Skill_WaterBullet::Create();
		break;
	}

	return newSkill;
}
