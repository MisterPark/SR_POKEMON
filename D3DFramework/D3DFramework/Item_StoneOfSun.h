#pragma once
#include "Item.h"
class Item_StoneOfSun :
    public Item
{
public:
    Item_StoneOfSun();
    virtual ~Item_StoneOfSun();

    virtual void Use() override;
};

