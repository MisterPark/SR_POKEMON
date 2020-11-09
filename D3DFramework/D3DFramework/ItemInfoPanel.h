#pragma once
#include "GameObject.h"

class Item;

class ItemInfoPanel : public GameObject
{
private:
	ItemInfoPanel();
	virtual ~ItemInfoPanel();

public:
	static ItemInfoPanel* GetInstance();
	static void Destroy();

	static void Show();
	static void Hide();

	static void SetTarget(Item* _item);

	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

private:
	Item* target = nullptr;

};

