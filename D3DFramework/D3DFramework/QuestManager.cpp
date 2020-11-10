#include "stdafx.h"
#include "QuestManager.h"

QuestManager* QuestManager::instance = nullptr;

QuestManager::QuestManager()
{
}


QuestManager::~QuestManager()
{
}
QuestManager* QuestManager::GetInstance()
{
	if (nullptr == instance) instance = new QuestManager;
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