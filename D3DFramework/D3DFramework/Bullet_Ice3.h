#pragma once
#include "Bullet.h"
class Bullet_Ice3 :
    public Bullet
{
public:
    Bullet_Ice3();
    virtual ~Bullet_Ice3();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

