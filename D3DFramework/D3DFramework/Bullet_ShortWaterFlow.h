#pragma once
#include "Bullet.h"
class Bullet_ShortWaterFlow :
    public Bullet
{
public:
    Bullet_ShortWaterFlow();
    virtual ~Bullet_ShortWaterFlow();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

};

