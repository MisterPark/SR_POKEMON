#pragma once
#include "Bullet.h"
class Bullet_GravityEnergyBall :
    public Bullet
{
public:
    Bullet_GravityEnergyBall();
    virtual ~Bullet_GravityEnergyBall();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

