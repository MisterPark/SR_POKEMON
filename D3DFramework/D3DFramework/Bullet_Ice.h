#pragma once
#include "Bullet.h"
class Bullet_Ice :
    public Bullet
{
public:
    Bullet_Ice();
    virtual ~Bullet_Ice();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

