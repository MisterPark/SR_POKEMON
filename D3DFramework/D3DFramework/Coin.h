#pragma once
#include "Character.h"
class Coin :
    public GameObject
{
public:
	Coin();
	Coin(const Vector3& pos, float money);
	virtual ~Coin();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void OnCollision(GameObject* target) override;
	void OnTerrain();

	Animation2D* anim = nullptr;
public:
	static Coin* Create(const Vector3& pos, float money);

private:
	bool offsetYAdd = false;
	float offsetY = 0.f;
	float lifeTime;
	float delay;
};

