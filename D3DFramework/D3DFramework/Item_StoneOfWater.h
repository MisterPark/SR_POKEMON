#pragma once
#include "Item.h"
class Item_StoneOfWater :
    public Item
{
public:
    Item_StoneOfWater();
    virtual ~Item_StoneOfWater();

    virtual void Use() override;
};

