#pragma once
#include "Item.h"
class Item_StoneOfMoon :
    public Item
{
public:
    Item_StoneOfMoon();
    virtual ~Item_StoneOfMoon();

    virtual void Use() override;
};

