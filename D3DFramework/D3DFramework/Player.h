#pragma once
#include "GameObject.h"
class Player :
    public GameObject
{

public:
    Player();
    ~Player();


    // GameObject��(��) ���� ��ӵ�
    virtual void Update() override;

};

