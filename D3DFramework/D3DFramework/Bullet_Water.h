#pragma once
#include "Bullet.h"
class Bullet_Water : //TODO : pvp�� ���� ��� �߰��� �ʿ���
    public Bullet
{
public:
    Bullet_Water();
    virtual ~Bullet_Water();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    
};