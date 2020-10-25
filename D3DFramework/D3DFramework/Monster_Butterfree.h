#pragma once
#include "Monster.h"
class Monster_Butterfree :
    public Monster
{
public:
    Monster_Butterfree();
    virtual ~Monster_Butterfree();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    void RandomMovePattern();

    void Attack();

private:
    Animation2D* ani;
};

