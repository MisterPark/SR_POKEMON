#pragma once
#include "Bullet.h"
class Bullet_FireShot :
    public Bullet
{
public:
    Bullet_FireShot();
    virtual ~Bullet_FireShot();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};
