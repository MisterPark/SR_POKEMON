#pragma once
#include "Monster.h"
class Oddish :
    public Monster
{
public:
    Oddish();
    virtual ~Oddish();
    // Monster을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();

};

