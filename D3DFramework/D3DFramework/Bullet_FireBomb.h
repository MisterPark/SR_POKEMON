#pragma once
#include "Bullet.h"
class Bullet_FireBomb :
    public Bullet
{
public:
    Bullet_FireBomb();
    virtual ~Bullet_FireBomb();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float gravityAccel = 0.f;
    float createDelay;
};

