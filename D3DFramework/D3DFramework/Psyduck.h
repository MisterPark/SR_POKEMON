#pragma once
#include "Monster.h"
class Psyduck :
    public Monster
{
public:
    Psyduck();
    virtual ~Psyduck();

    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void MovePattern();
    void Attack();

};
