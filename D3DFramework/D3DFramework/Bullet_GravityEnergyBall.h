#pragma once
#include "Bullet.h"
class Bullet_GravityEnergyBall :
    public Bullet
{
public:
    Bullet_GravityEnergyBall();
    virtual ~Bullet_GravityEnergyBall();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

