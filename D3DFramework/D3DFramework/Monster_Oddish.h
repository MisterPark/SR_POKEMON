#pragma once
#include "Monster.h"
class Monster_Oddish :
    public Monster
{
public:
    Monster_Oddish();
    virtual ~Monster_Oddish();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    void Parttern();
    void RandomMovePattern();
    void Attack();



};

