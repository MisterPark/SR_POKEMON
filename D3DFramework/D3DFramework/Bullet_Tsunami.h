#pragma once
#include "Bullet.h"
class Bullet_Tsunami :
    public Bullet
{
public:
    Bullet_Tsunami();
    virtual ~Bullet_Tsunami();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float angleX = 10.f;
    bool angleXAdd = false;
};

