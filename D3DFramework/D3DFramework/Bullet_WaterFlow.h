#pragma once
#include "Bullet.h"
class Bullet_WaterFlow :
    public Bullet
{
public:
    Bullet_WaterFlow();
    virtual ~Bullet_WaterFlow();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

