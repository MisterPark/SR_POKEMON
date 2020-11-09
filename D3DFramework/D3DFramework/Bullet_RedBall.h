#pragma once
#include "Bullet.h"
class Bullet_RedBall :
    public Bullet
{
public:
    Bullet_RedBall();
    virtual ~Bullet_RedBall();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

