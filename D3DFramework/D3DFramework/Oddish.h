#pragma once
#include "Monster.h"
class Oddish :
    public Monster
{
public:
    Oddish();
    virtual ~Oddish();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    void Parttern();
    void RandomMovePattern();

};

