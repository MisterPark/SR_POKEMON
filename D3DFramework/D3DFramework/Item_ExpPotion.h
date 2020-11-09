#pragma once
#include "Item.h"
class Item_ExpPotion :
    public Item
{
public:
    Item_ExpPotion();
    virtual ~Item_ExpPotion();

    virtual void Use() override;
};

