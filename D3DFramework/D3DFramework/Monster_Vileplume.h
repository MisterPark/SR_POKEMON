#pragma once
#include "Monster.h"
class Monster_Vileplume :
    public Monster
{
public:
    Monster_Vileplume();
    virtual ~Monster_Vileplume();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    void Parttern();
    void RandomMovePattern();
    void Attack(Transform* PlayerT);
    void CreateBullet(Transform* PlayerT);

    bool AttackDelay;
};

