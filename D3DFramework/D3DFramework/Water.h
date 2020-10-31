#pragma once
#include "GameObject.h"
#include "Terrain.h"
class Water : public GameObject
{
public:
	Water();
	virtual ~Water();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;


	Terrain* terrain = nullptr;
};
