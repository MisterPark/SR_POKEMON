#pragma once
#include "Monster.h"
class Poliwrath :
    public Monster
{
public:
    Poliwrath();
    virtual ~Poliwrath();

    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void RandomMovePattern();
    void Attack(Transform* PlayerT);
    void CreateBullet(Transform* PlayerT);

    
    bool AttackDelay;
};

