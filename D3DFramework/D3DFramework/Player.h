#pragma once
#include "Character.h"

class Player
{
private:
    Player();
    virtual ~Player();

public:
	static Player* GetInstance();
	static void DestroyInstance();

public:
	void Update();

	void SetCharacter(Character* object);
	Character* GetCharacter() { return character; }

private:
	void Initialize();
	void Release();

private:
	void ResetMousePoint();
	void CalcSpawnTime();
	void Attack();
	void CalcMouse();
	void KeyInput();

private:
	static Player* instance;

	Character* character = nullptr;
	float radianX = 0.f;
	float radianY = 0.f;
	float spawnTime = 0.f;
	bool canSpawn = true;
	bool isFix = true;
};

