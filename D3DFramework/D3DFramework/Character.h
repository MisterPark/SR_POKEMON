#pragma once
#include "GameObject.h"
class Character :
    public GameObject
{
public:
    Character();
    virtual ~Character();
    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;

    // GameObject��(��) ���� ��ӵ�
    virtual void Initialize() override;
    virtual void Release() override;
};

