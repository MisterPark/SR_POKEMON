#pragma once
#include "Item.h"
class Item_StoneOfAwake :
    public Item
{
public:
    Item_StoneOfAwake();
    virtual ~Item_StoneOfAwake();

    virtual void Use() override;
};

