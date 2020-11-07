#pragma once
#include "Bullet.h"
class Bullet_WaterBomb :
    public Bullet
{
public:
    Bullet_WaterBomb();
    virtual ~Bullet_WaterBomb();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float gravityAccel = 0.f;
    float createDelay;
};

