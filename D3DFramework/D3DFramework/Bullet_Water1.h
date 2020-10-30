#pragma once
#include "Bullet.h"
class Bullet_Water1 : //TODO : pvp를 위해 기능 추가가 필요함
    public Bullet
{
public:
    Bullet_Water1();
    virtual ~Bullet_Water1();
    // Character을(를) 통해 상속됨
    virtual void Update() override;
    virtual void Render() override;
    virtual void OnCollision(GameObject* target) override;

private:
    float Time[3];  // 프레임(시간) 재는용도

};