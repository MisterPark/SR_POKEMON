#pragma once
#include "GameObject.h"
class UI :
    public GameObject
{
public:
    UI();
    virtual ~UI();

    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;

};

