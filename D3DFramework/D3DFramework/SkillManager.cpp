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
		// 쿨다운이 진행중일 때
		if (skill->GetIsCoolDown())
		{
			skill->CalcCoolTime();
		}

		// 스킬이 액티브 중일 때
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
	case SkillName::Rush:
		newSkill = Skill_Rush::Create();
		break;
	case SkillName::TearsBullet:
		newSkill = Skill_TearsBullet::Create();
		break;
	case SkillName::TearsBullet2:
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
	case SkillName::IceBullet:
		newSkill = Skill_IceBullet::Create();
		break;
	case SkillName::IceBullet2:
		newSkill = Skill_IceBullet2::Create();
		break;
	case SkillName::IceBullet3:
		newSkill = Skill_IceBullet3::Create();
		break;
	case SkillName::BubbleBullet:
		newSkill = Skill_BubbleBullet::Create();
		break;
	case SkillName::BubbleBullet2:
		newSkill = Skill_BubbleBullet2::Create();
		break;
	case SkillName::XClaw:
		newSkill = Skill_XClaw::Create();
		break;
	case SkillName::HealBubble:
		newSkill = Skill_HealBubble::Create();
		break;

	}

	return newSkill;
}
