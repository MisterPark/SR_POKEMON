#include "stdafx.h"
#include "Skill_Meteor.h"
#include "Effect.h"
#include "Meteor.h"

Skill_Meteor::Skill_Meteor()
{
	skillIcon = TextureKey::ICON_XCLAW;
	moveStopTime = 0.4f;
}

Skill_Meteor::~Skill_Meteor()
{
}

void Skill_Meteor::InitCoolTime()
{
	maxCoolTime = coolTime = 10.f;
}

void Skill_Meteor::InitActiveTime()
{
	activeTime = 0.f;
}

void Skill_Meteor::Update()
{

	CalcActiveTime();
}

void Skill_Meteor::CalcActiveTime()
{
	if (isActive)
	{
		activeTime -= TimeManager::DeltaTime();
		if (0.f > activeTime)
		{
			SetNoneActive();
		}
	}
}

Skill * Skill_Meteor::Create()
{
	Skill* instance = new Skill_Meteor;

	return instance;
}