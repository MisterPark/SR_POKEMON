#pragma once
#include "GameObject.h"
#include "Terrain.h"
class Environment : public GameObject
{
public:
	Environment();
	virtual ~Environment();

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;

	
	Terrain* terrain = nullptr;
};

