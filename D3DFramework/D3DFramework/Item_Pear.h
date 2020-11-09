#pragma once
#include "Item.h"
class Item_Pear :
    public Item
{
public:
    Item_Pear();
    virtual ~Item_Pear();

    virtual void Use() override;
};

