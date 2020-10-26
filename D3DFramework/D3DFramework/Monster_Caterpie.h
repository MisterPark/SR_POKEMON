#pragma once
#include "Monster.h"
class Monster_Caterpie :
    public Monster
{
public:
    Monster_Caterpie();
    virtual ~Monster_Caterpie();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;


private:
    Animation2D* ani;
};

