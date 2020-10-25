#pragma once
#include "GameObject.h"
class UI :
    public GameObject
{
public:
    UI();
    virtual ~UI();

    // GameObject을(를) 통해 상속됨
    virtual void Update() override;

};

