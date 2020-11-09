#pragma once
#include "Item.h"
class Item_Clam :
    public Item
{
public:
    Item_Clam();
    virtual ~Item_Clam();

    virtual void Use() override;
};

