#pragma once
#include "Monster.h"
class Jynx :
    public Monster
{
public:
    Jynx();
    virtual ~Jynx();

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
