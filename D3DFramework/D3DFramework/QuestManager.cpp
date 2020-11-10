#include "stdafx.h"
#include "QuestManager.h"

QuestManager* QuestManager::instance = nullptr;

QuestManager::QuestManager()
{
	for (int i = 0; i < NpcName::NPC_END; i++)
	{
		progress[i] = 0;
	}
	for (int i = 0; i < (int)MonsterType::END; i++)
	{
		killCount[i] = 0;
	}
}


QuestManager::~QuestManager()
{
}
QuestManager* QuestManager::GetInstance()
{
	if (nullptr == instance) instance = new QuestManager;
	instance->killCount[(int)MonsterType::END];
	return instance;
}

void QuestManager::Destroy()
{
	if (nullptr != instance)
	{
		delete instance;
		instance = nullptr;
	}
}