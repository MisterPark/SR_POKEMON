#pragma once

class Item;

class Slot
{
public:
	Slot();
	~Slot();

	Item* GetItem();
	Item* SetItem(Item* inItem);

	void Update();
	void Render();
	
private:
	Item* item = nullptr;
public:
	Vector3 position;
};

