#pragma once
#include "Bullet.h"
class Bullet_DarkBall :
    public Bullet
{
public:
    Bullet_DarkBall();
    virtual ~Bullet_DarkBall();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

