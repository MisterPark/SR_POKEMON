#pragma once
#include "Item.h"
class Item_StoneOfLeaf :
    public Item
{
public:
    Item_StoneOfLeaf();
    virtual ~Item_StoneOfLeaf();

    virtual void Use() override;
};

