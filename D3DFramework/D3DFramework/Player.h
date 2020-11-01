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

private:
	void Initialize();
	void Release();

private:
	void ResetMousePoint();
	void CalcCoolTime();
	void Attack();
	void CalcMouse();
	void KeyInput();
	void ChangeState(State state);

private:
	static Player* instance;

	Character* character;
	float radianX;
	float radianY;
	float attackCoolTime;
	float skillCoolTime;
	bool isAttack;
	bool isSkill;
	bool isFix;
};

