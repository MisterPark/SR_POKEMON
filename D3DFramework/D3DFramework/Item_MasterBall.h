#pragma once
#include "Item.h"
class Item_MasterBall :
    public Item
{
public:
    Item_MasterBall();
    virtual ~Item_MasterBall();

    virtual void Use() override;
};

