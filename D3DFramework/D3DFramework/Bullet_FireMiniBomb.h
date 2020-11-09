#pragma once
#include "Bullet.h"
class Bullet_FireMiniBomb :
    public Bullet
{
public:
    Bullet_FireMiniBomb();
    virtual ~Bullet_FireMiniBomb();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float gravityAccel = 0.f;
    float createDelay;
};

