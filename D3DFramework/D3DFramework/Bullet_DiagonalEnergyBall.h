#pragma once
#include "Bullet.h"
class Bullet_DiagonalEnergyBall :
    public Bullet
{
public:
    Bullet_DiagonalEnergyBall();
    virtual ~Bullet_DiagonalEnergyBall();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

