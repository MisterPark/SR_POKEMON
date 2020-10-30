#pragma once
#include "Monster.h"
class Butterfree :
    public Monster
{
public:
    Butterfree();
    virtual ~Butterfree();
    // Monster을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void Attack();
};

