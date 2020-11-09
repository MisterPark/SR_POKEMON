#pragma once
#include "Item.h"
class Item_StoneOfThunder :
    public Item
{
public:
    Item_StoneOfThunder();
    virtual ~Item_StoneOfThunder();

    virtual void Use() override;
};

