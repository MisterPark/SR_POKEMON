#pragma once
#include "GameObject.h"
class UI :
    public GameObject
{
public:
    UI();
    virtual ~UI();

    virtual void Update() override;
    virtual void Initialize() override;
    virtual void Release() override;

};

