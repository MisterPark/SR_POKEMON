#pragma once
#include "Item.h"
class Item_StoneOfDark :
    public Item
{
public:
    Item_StoneOfDark();
    virtual ~Item_StoneOfDark();

    virtual void Use() override;
};

