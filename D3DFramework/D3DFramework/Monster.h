#pragma once
#include "Character.h"

class Monster :
    public Character
{
public:
    
public:
    Monster();
    virtual ~Monster();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

protected:
    

protected:
    int Frame[3]; // �����Ǵ�
    float Time[5];  // ������(�ð�) ��¿뵵

    
};

