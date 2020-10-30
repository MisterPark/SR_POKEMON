#pragma once
#include "Monster.h"
class Golduck :
    public Monster
{
public:
    Golduck();
    virtual ~Golduck();

    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void RandomMovePattern();
    void Attack(Transform* PlayerT);
    void CreateBullet(Transform* PlayerT);

    
    bool AttackDelay;
};

