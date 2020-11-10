#pragma once
class QuestManager
{
private:
	QuestManager();
	~QuestManager();

public:
	static QuestManager* GetInstance();
	static void Destroy();

private:
	static QuestManager* instance;

	
};

