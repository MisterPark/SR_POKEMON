#pragma once
#include "Bullet.h"
class Bullet_Water : //TODO : pvp를 위해 기능 추가가 필요함
    public Bullet
{
public:
    Bullet_Water();
    virtual ~Bullet_Water();
    // Bullet을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    void SetDir(float fX, float fZ, float fY = 0.f) { MoveDir.x = fX; MoveDir.y = fY; MoveDir.z = fZ; }

};

