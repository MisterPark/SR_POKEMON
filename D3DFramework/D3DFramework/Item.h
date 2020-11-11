#pragma once
#include "GameObject.h"

enum class ItemType : int
{
	NONE,
	TOMATO,
	CLAM,
	GRAPE,
	PEAR,
	GAJI,
	LEMON,
	BLUEBERRY,
	HP_POTION,
	EXP_POTION,
	STONE_OF_FIRE, 
	STONE_OF_WATER,
	STONE_OF_LEAF,
	STONE_OF_THUNDER,
	STONE_OF_MOON,
	STONE_OF_SUN,
	STONE_OF_LIGHT,
	STONE_OF_AWAKE,
	STONE_OF_DARK, 
	POKE_BALL, 
	GREAT_BALL,
	ULTRA_BALL,
	MASTER_BALL,
};

class Item : public GameObject
{
public:
	Item();
	virtual ~Item();


	virtual void Initialize() override;
	virtual void Release() override;
	virtual void Update() override;

	virtual void OnCollision(GameObject* target) override;

	virtual void Use() = 0;

	void OnTerrain();
	void UpDown();

	static Item* CreateRandom();

public:
	Animation2D* anim = nullptr;
	bool inSlot = false;
	int count = 1;
	ItemType type = ItemType::NONE;
	wstring description;
private:
	float offsetY;
	float downTick = 0.f;
	float downDuration = 1.f;
	bool downFlag = false;

};

