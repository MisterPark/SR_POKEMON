#pragma once
#include "Bullet.h"
class Bullet_Explosion :
    public Bullet
{
public:
    Bullet_Explosion();
    virtual ~Bullet_Explosion();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float delay = 0.f;
};

