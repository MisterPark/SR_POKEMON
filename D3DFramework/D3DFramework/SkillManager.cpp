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

	case SkillName::Blaze:
		newSkill = Skill_Blaze::Create();
		break;
	case SkillName::Tornado:
		newSkill = Skill_Tornado::Create();
		break;
	case SkillName::RushAttack:
		newSkill = Skill_RushAttack::Create();
		break;
	case SkillName::TearsBullet:
		newSkill = Skill_TearsBullet::Create();
		break;
	case SkillName::CrossBullet:
		newSkill = Skill_CrossBullet::Create();
		break;
	case SkillName::XBullet:
		newSkill = Skill_XBullet::Create();
		break;
	case SkillName::WebBullet:
		newSkill = Skill_WebBullet::Create();
		break;
	}

	return newSkill;
}
