#pragma once
#include "Monster.h"
class Poliwag :
    public Monster
{
public:
    Poliwag();
    virtual ~Poliwag();

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
