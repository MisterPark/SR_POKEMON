#pragma once
#include "Character.h"

class Player
{
private:
    Player();
    virtual ~Player();

public:
	static Player* GetInstance();
	static void Destroy();

public:
	void Update();
	void PostUpdate();

public:
	// Setter
	void SetCharacter(Character* object);
	void SetRadianX(float _x) { radianX = _x; }
	// 45도 1시 90 3시 180도 7시 270 11시
	void SetRadianY(float _y) { radianY = _y; }

public:
	// Getter
	Character* GetCharacter() { return character; }
	float GetRadianX() { return radianX; }
	float GetRadianY() { return radianY; }
	float GetMetaMorphoTime() { return metamorphosisTime; }
	int GetCurrentSkillIndex() { return skillNum; }
	Pokemon GetMetamorphoPokemonNumber() { return nextPokemon.second; }

private:
	void Initialize();
	void Release();

private:
	void ResetMousePoint();
	void Attack();
	void CalcMouse();
	void KeyInput();
	void ChangeState(State state);
	void SetCharacterByNumber(MonsterType type);
	void CalcMetamorphosisTime();
	void ComeBackFromMetamorpho();

public:
	void Metamorphosis();
	void ChangeNextPokemon(MonsterType pokemon, Pokemon number);

private:
	static Player* instance;
	Character* character = nullptr;
	vector<pair<MonsterType, Pokemon>> metamorphosisList;
	pair<MonsterType, Pokemon> nextPokemon;
	float radianX;
	float radianY;
	float metamorphosisTime;

	bool isFix;
	bool canMetamorphosis;
	
	int skillNum;
	int skillSetSize;
	int pokemonIndex;
};

