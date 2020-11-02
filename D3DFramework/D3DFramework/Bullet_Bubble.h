#pragma once
#include "Bullet.h"
class Bullet_Bubble :
    public Bullet
{
public:
    Bullet_Bubble();
    virtual ~Bullet_Bubble();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

