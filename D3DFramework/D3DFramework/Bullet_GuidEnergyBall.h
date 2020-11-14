#pragma once
#include "Bullet.h"
class Bullet_GuidEnergyBall :
    public Bullet
{
public:
    Bullet_GuidEnergyBall();
    virtual ~Bullet_GuidEnergyBall();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    Vector3 guidPos = { 0.f, 0.f, 0.f };
    float guidAccelDecTime = 0.f;
    bool guid = false;
    bool guidAccelDec = false;
};

