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

void SkillManager::Update()
{
	for (auto& skill : skillList)
	{
		if (skill->GetIsActive())
		{
			skill->Update();
		}
	}
}

void SkillManager::PostUpdate()
{
	for (auto& skill : skillList)
	{
		if (skill->GetIsActive())
		{
			if (0.f > skill->GetActiveTime())
				skill->SetNoneActive();
		}
	}
}

void SkillManager::AddSkillToList(Skill * skill)
{
	if (IsSkillInList(skill)) return;

	skillList.emplace_back(skill);
}

void SkillManager::DeleteSkillFromList(Skill * skill)
{
	auto iter = find_if(skillList.begin(), skillList.end(), [skill](Skill* elem)
	{
		return elem == skill;
	});

	if (skillList.end() == iter) return;

	skillList.erase(iter);
}

bool SkillManager::IsSkillInList(Skill * skill)
{
	auto iter = find_if(skillList.begin(), skillList.end(), [skill](Skill* elem)
	{
		return elem == skill;
	});

	if (skillList.end() == iter) return false;
	return true;
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
