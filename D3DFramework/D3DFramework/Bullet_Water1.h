#pragma once
#include "Bullet.h"
class Bullet_Water1 : //TODO : pvp�� ���� ��� �߰��� �ʿ���
    public Bullet
{
public:
    Bullet_Water1();
    virtual ~Bullet_Water1();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float Time[3];  // ������(�ð�) ��¿뵵

};