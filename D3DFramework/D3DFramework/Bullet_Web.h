#pragma once
#include "Bullet.h"
class Bullet_Web :
    public Bullet
{
public:
    Bullet_Web();
    virtual ~Bullet_Web();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

