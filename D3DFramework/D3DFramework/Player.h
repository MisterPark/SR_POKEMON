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
	void Evolution();

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
	int GetCurrentSkillIndex() { return skillNum; }
	void SetCatchMonster(Pokemon pokemon) { catchMonster = pokemon; }

private:
	void Initialize();
	void Release();

private:
	void ResetMousePoint();
	void Attack();
	void CalcMouse();
	void KeyInput();
	void ChangeState(State state);

private:
	static Player* instance;

	Character* character = nullptr;
	Pokemon catchMonster = Pokemon::None; 
	float radianX;
	float radianY;
	bool isFix;
	int skillNum;
	int skillSetSize;
};

