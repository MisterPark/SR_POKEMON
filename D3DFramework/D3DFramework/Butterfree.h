#pragma once
#include "Monster.h"
class Butterfree :
    public Monster
{
public:
    Butterfree();
    virtual ~Butterfree();
    // Monster��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

private:
    void Pattern();
    void Attack();
};

