#pragma once
#include "Bullet.h"
class Bullet_RedBall :
    public Bullet
{
public:
    Bullet_RedBall();
    virtual ~Bullet_RedBall();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

