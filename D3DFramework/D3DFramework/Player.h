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

	static void Show();
	static void Hide();

public:
	void Initialize();
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
	int GetDittoColor() { return dittoColor; }
	void AddDittoColor() { dittoColor++; if (dittoColor == 5) dittoColor = 0; return; }
	void MetamorphoEffect();

private:
	void Release();

private:
	void CharacterCheck();
	void AttackCheat();
	void ResetMousePoint();
	void Attack();
	void CalcMouse();
	void KeyInput();
	void ChangeState(State state);
	void SetCharacterByType(TYPE type);
	void CalcMetamorphosisTime();
	void ComeBackFromMetamorpho();

public:
	void Metamorphosis();
	void PermanentMetamorphosis();
	void MetamorphosisToDitto();

	void ChangeNextPokemon(TYPE pokemon, Pokemon number);

private:
	static Player* instance;
	Character* character = nullptr;
	vector<pair<TYPE, Pokemon>> metamorphosisList;
	pair<TYPE, Pokemon> nextPokemon;
	float radianX;
	float radianY;
	float metamorphosisTime;
	float originIncreaseAttack;
	float originDefaultAttack;

	bool isFix;
	bool canMetamorphosis;
	bool isAttackCheat;
	
	int skillNum;
	int skillSetSize;
	int pokemonIndex;
	int permanentIndex;

	int dittoColor;
};

