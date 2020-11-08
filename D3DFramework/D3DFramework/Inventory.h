#pragma once
#define dfSLOT_COL_COUNT 5
#define dfSLOT_ROW_COUNT 3
#define dfMAX_SLOT_COUNT (dfSLOT_COL_COUNT * dfSLOT_ROW_COUNT)

#include"Slot.h"
class Item;

class Inventory
{
private:
	Inventory();
	~Inventory();

public:
	static Inventory* GetInstance();
	static void Destroy();

	static void Show();
	static void Show(bool on);
	static void Hide();

	static void Update();
	static void Render();

	static bool Push(Item* item);

private:
	void UpdateUI();

private:
	Slot slots[dfMAX_SLOT_COUNT] = {  };
	
public:
	Vector3 position;
	bool isEnable = false;
	bool isVisible = false;

};

