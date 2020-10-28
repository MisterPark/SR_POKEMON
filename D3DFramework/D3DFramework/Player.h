#pragma once
#include "Character.h"
#include "Animation2D.h"

class Player : public Character
{
public:
	

public:
    Player();
    virtual ~Player();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	void ChangeAnim(State state, DIR dir);

private:
	void ResetMousePoint();
	void CalcSpawnTime();
	void SpawnBullet();
	void CalcMouse();
	void KeyInput();
	void SetAnim();

private:
	float radianX = 0.f;
	float radianY = 0.f;
	float spawnTime = 0.f;
	bool canSpawn = true;
};

