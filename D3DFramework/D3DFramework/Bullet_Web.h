#pragma once
#include "Bullet.h"
class Bullet_Web :
    public Bullet
{
public:
    Bullet_Web();
    virtual ~Bullet_Web();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

