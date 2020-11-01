#pragma once
#include "UI.h"
class Button :
    public UI
{
public:
    Button();
    virtual ~Button();

    virtual void Update() override;
};

