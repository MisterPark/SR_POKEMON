#pragma once
#include "Item.h"
class Item_StoneOfLight :
    public Item
{
public:
    Item_StoneOfLight();
    virtual ~Item_StoneOfLight();

    virtual void Use() override;
};

