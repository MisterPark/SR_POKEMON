#pragma once
#include "Item.h"
class Item_BlueBerry :
    public Item
{
public:
    Item_BlueBerry();
    virtual ~Item_BlueBerry();

    virtual void Use() override;
};

