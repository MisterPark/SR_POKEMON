#pragma once
#include "Item.h"
class Item_Gaji :
    public Item
{
public:
    Item_Gaji();
    virtual ~Item_Gaji();

    virtual void Use() override;
};

