#pragma once
#include "Character.h"

class Tree :
    public Character
{
public:

public:
    Tree();
    virtual ~Tree();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;

    
    void UpdateAnimation();
protected:
    int Frame[3]; // �����Ǵ�
    float Time[5];  // ������(�ð�) ��¿뵵
    bool isSearch = false;
    float disPlayer = 0.f;

};

