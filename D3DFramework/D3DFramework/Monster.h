#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    Monster();
    virtual ~Monster();
    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;


};

