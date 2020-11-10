#pragma once
enum NpcName{
	CELEBI, DOCTOR_OH, NPC_END
};

class QuestManager
{
private:
	QuestManager();
	~QuestManager();

public:
	static QuestManager* GetInstance();
	static void Destroy();
	int GetProgress(NpcName npc) { return progress[npc]; }


private:
	static QuestManager* instance;

	int progress[NpcName::NPC_END];
};

