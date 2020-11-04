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
	// 45�� 1�� 90 3�� 180�� 7�� 270 11��
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
	void Attack();
	void CalcMouse();
	void KeyInput();
	void ChangeState(State state);

private:
	static Player* instance;

	Character* character;
	float radianX;
	float radianY;
	bool isFix;
	int skillNum;
};

