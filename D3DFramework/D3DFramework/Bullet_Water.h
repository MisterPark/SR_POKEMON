#pragma once
#include "Bullet.h"
class Bullet_Water : //TODO : pvp�� ���� ��� �߰��� �ʿ���
    public Bullet
{
public:
    Bullet_Water();
    virtual ~Bullet_Water();
    // Bullet��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    void SetDir(float fX, float fZ, float fY = 0.f) { MoveDir.x = fX; MoveDir.y = fY; MoveDir.z = fZ; }

};

