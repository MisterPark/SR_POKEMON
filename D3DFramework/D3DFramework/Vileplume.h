#pragma once
#include "Monster.h"
class Vileplume :
    public Monster
{
public:
    Vileplume();
    virtual ~Vileplume();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

private:
    void Parttern();
    void RandomMovePattern();
    void Attack(Transform* PlayerT);
    void CreateBullet(Transform* PlayerT);

    bool AttackDelay;
};


