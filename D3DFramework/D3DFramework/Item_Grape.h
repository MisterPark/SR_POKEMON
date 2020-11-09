#pragma once
#include "Item.h"
class Item_Grape :
    public Item
{
public:
    Item_Grape();
    virtual ~Item_Grape();

    virtual void Use() override;
};

