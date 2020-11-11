#pragma once
enum NpcName{
	CELEBI, DOCTOR_OH, CHARMANDER, BULBASAUR, SQUIRTLE, NPC_END
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
	void SetProgress(NpcName npc, int Prog) { progress[npc] = Prog; }
	void AddProgress(NpcName npc) { progress[npc]++; }
	int GetMonsterKill(MonsterType monster) { return killCount[(int)monster]; }
	void SetMonsterKill(MonsterType monster, int count) { killCount[(int)monster] = count; }
	void AddMonsterKill(MonsterType monster) { killCount[(int)monster]++; }

private:
	static QuestManager* instance;

	int progress[NpcName::NPC_END];
	//자동으로 쌓임
	int killCount[(int)MonsterType::END];
};

