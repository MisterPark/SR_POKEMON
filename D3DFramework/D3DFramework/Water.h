#pragma once
#include "GameObject.h"
#include "Terrain.h"
#include "Animation2D.h"
class Water : public GameObject
{
public:
	Water();
	virtual ~Water();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;

	void Lava();
	Animation2D* anim = nullptr;
	Terrain* terrain = nullptr;
	bool isWater = false;
private:
	float animSpeed;

	TextureKey startKey;
	TextureKey endKey;

	bool isLoop;
	
};
