#pragma once
#include "Monster.h"
class Suicune :
    public Monster
{
public:
    Suicune();
    virtual ~Suicune();

    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void RandomMovePattern();
    void Attack(Transform* PlayerT);
    void CreateBullet(Transform* PlayerT);

    bool isSearch = false;
    bool AttackDelay;
};

