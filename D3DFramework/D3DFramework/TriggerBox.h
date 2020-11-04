#pragma once
#include "GameObject.h"
#include "Animation2D.h"
class TriggerBox :
	public GameObject
{
public:
	TriggerBox();
	~TriggerBox();

	// GameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;

	virtual void OnCollision(GameObject* target);
	void OnTerrain();

	void Portal();

	Animation2D* anim = nullptr;
	
public:
	void(*OnTriggered)() = nullptr;

private:
	float offsetY;
};

