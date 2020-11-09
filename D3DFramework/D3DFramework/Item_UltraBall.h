#pragma once
#include "Item.h"
class Item_UltraBall :
    public Item
{
public:
    Item_UltraBall();
    virtual ~Item_UltraBall();

    virtual void Use() override;
};

