#include "stdafx.h"
#include "Bullet_Water1.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Bullet_Water1::Bullet_Water1()
{   //TODO : 불렛이 지형타는중
    SetTexture(State::IDLE, TextureKey::BULLET_WATER1_01, 1, 1);
    UpdateAnimation();
    state = State::IDLE;
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

    for (int i = 0; i < 3; i++)
    {
        Time[i] = 0;
    }

    transform->scale.x *= 0.5f;
    transform->scale.y *= 0.5f;
    transform->scale.z *= 0.5f;

    moveSpeed = 6.f;
}

Bullet_Water1::~Bullet_Water1()
{
}

void Bullet_Water1::Update()
{

    Bullet::Update();

    transform->position += direction * moveSpeed * TimeManager::DeltaTime();;


    Time[0] += TimeManager::DeltaTime();
    if (Time[0] >= 5.f) {
        isDead = true;
    }
    Billboard();
}

void Bullet_Water1::Render()
{
    Bullet::Render();
}

void Bullet_Water1::OnCollision(GameObject* target)
{
    if (target->isAlliance == this->isAlliance) {
        return;
    }

    //if (dynamic_cast<Player*>(target)) {
       //몬스터와 충돌 이벤트
    /*isDead = true;*/
    //}
}