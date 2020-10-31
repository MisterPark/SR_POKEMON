#pragma once
#include "Character.h"

class Tree :
    public Character
{
public:

public:
    Tree();
    virtual ~Tree();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;

    
    void UpdateAnimation();
protected:
    int Frame[3]; // 패턴판단
    float Time[5];  // 프레임(시간) 재는용도
    bool isSearch = false;
    float disPlayer = 0.f;

};

