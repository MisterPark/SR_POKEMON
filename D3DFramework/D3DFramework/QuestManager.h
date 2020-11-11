#pragma once
enum NpcName{
	CELEBI, DOCTOR_OH, CHARMANDER, BULBASAUR, SQUIRTLE, COLOR_DITTO, NPC_END
};
enum Event {
	EVENT_TUTORIAL, EVENT_TOWN, EVENT_END
};


class QuestManager
{
private:
	QuestManager();
	~QuestManager();

public:
	static QuestManager* GetInstance();
	static void Destroy();
	int GetProgress(Event event,NpcName npc) { return progress[event][npc]; }
	void SetProgress(Event event,NpcName npc, int Prog) { progress[event][npc] = Prog; }
	void AddProgress(Event event,NpcName npc) { progress[event][npc]++; }
	int GetMonsterKill(MonsterType monster) { return killCount[(int)monster]; }
	void SetMonsterKill(MonsterType monster, int count) { killCount[(int)monster] = count; }
	void AddMonsterKill(MonsterType monster) { killCount[(int)monster]++; }

	int GetEvolution(NpcName npc) { return evolution[npc]; }
	void SetEvolution(NpcName npc, int count) { evolution[npc] = count; }
	void AddEvolution(NpcName npc) { evolution[npc]++; }

	Event GetEvent() { return eventProgress; }
	void SetEvent(Event _event) { eventProgress = _event; }

private:
	static QuestManager* instance;

	Event eventProgress = Event::EVENT_END;
	int progress[Event::EVENT_END][NpcName::NPC_END];
	//자동으로 쌓임
	int killCount[(int)MonsterType::END];
	int evolution[NpcName::NPC_END];
};

