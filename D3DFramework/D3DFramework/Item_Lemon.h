#pragma once
#include "Item.h"
class Item_Lemon :
    public Item
{
public:
    Item_Lemon();
    virtual ~Item_Lemon();

    virtual void Use() override;
};

