#pragma once
#include "Bullet.h"
class Bullet_ShortWaterFlow :
    public Bullet
{
public:
    Bullet_ShortWaterFlow();
    virtual ~Bullet_ShortWaterFlow();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

