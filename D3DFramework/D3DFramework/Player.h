#pragma once
#include "PlayerCharacter.h"

class Player : public GameObject
{
public:
    Player();
	Player(PlayerCharacter* _character);
    virtual ~Player();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	static Player* Create(PlayerCharacter* _character);

private:
	void ResetMousePoint();
	void CalcSpawnTime();
	void Attack();
	void CalcMouse();
	void KeyInput();

private:
	PlayerCharacter* character = nullptr;
	float radianX = 0.f;
	float radianY = 0.f;
	float spawnTime = 0.f;
	bool canSpawn = true;
};

