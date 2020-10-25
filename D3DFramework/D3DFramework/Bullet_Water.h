#pragma once
#include "Character.h"
class Bullet_Water : //TODO : pvp를 위해 기능 추가가 필요함
    public Character
{
public:
    Bullet_Water();
    virtual ~Bullet_Water();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

    void SetDir(float fX, float fZ) { MoveDir.x = fX; MoveDir.z = fZ; }
private:
    float Time[3];  // 프레임(시간) 재는용도
    Vector3 MoveDir;
};

