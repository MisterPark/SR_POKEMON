#pragma once
#include "Item.h"
class Item_StoneOfFire :
    public Item
{
public:
    Item_StoneOfFire();
    virtual ~Item_StoneOfFire();

    virtual void Use() override;
};

