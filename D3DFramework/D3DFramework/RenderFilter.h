#pragma once
#include "GameObject.h"

class RenderFilter : public GameObject
{
private:
	RenderFilter();
	~RenderFilter();

public:
	static RenderFilter* GetInstance();
	static void Destroy();


	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	

};

