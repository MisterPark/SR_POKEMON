#pragma once
#include "Item.h"
class Item_HpPotion :
    public Item
{
public:
    Item_HpPotion();
    virtual ~Item_HpPotion();

    virtual void Use() override;
};

