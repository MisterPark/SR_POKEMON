#pragma once
#include "Bullet.h"
class Bullet_Bubble2 :
    public Bullet
{
public:
    Bullet_Bubble2();
    virtual ~Bullet_Bubble2();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

