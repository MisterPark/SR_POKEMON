#pragma once
#include "GameObject.h"

class Monster :
    public GameObject
{
public:
    Monster();
    virtual ~Monster();
    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

};

