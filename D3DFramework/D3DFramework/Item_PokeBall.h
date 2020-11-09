#pragma once
#include "Item.h"
class Item_PokeBall :
    public Item
{
public:
    Item_PokeBall();
    virtual ~Item_PokeBall();

    virtual void Use() override;
};

