#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    Monster();
    virtual ~Monster();
    // GameObject을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;


};

