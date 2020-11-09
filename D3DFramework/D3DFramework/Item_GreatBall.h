#pragma once
#include "Item.h"
class Item_GreatBall :
    public Item
{
public:
    Item_GreatBall();
    virtual ~Item_GreatBall();

    virtual void Use() override;
};

