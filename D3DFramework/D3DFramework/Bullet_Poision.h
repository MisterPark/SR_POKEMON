#pragma once
#include "Bullet.h"
class Bullet_Poision :
    public Bullet
{
public:
    Bullet_Poision();
    virtual ~Bullet_Poision();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;


};