#pragma once
#include "GameObject.h"

class Item : public GameObject
{
public:
	Item();
	virtual ~Item();


	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;

	virtual void OnCollision(GameObject* target) override;
	void OnTerrain();
	void UpDown();

public:
	Animation2D* anim = nullptr;
	bool inSlot = false;
private:
	float offsetY;
	float downTick = 0.f;
	float downDuration = 1.f;
	bool downFlag = false;

};

