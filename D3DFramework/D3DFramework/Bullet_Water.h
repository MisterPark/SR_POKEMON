#pragma once
#include "Character.h"
class Bullet_Water : //TODO : pvp�� ���� ��� �߰��� �ʿ���
    public Character
{
public:
    Bullet_Water();
    virtual ~Bullet_Water();
    // Character��(��) ���� ��ӵ�
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    void SetDir(float fX, float fZ, float fY = 0.f) { MoveDir.x = fX; MoveDir.y = fY; MoveDir.z = fZ; }
    private:
    float Time[3];  // ������(�ð�) ��¿뵵
    Vector3 MoveDir;
};