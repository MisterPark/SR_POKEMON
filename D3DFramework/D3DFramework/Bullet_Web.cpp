#include "stdafx.h"
#include "Bullet_Web.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Bullet_Web::Bullet_Web()
{   //TODO : 불렛이 지형타는중
    SetTexture(State::IDLE, TextureKey::BULLET_WEB1_01, 1, 1);
    UpdateAnimation();
    state = State::IDLE;
    anim->SetLoop(true);
    anim->SetDelay(0.2f);

    transform->scale.x *= 0.5f;
    transform->scale.y *= 0.5f;
    transform->scale.z *= 0.5f;

    isDeadTime = 4.5f;
    moveSpeed = 3.f;
}

Bullet_Web::~Bullet_Web()
{
}

void Bullet_Web::Update()
{

    Bullet::Update();

    transform->position += direction * moveSpeed * TimeManager::DeltaTime();;


    Time[0] += TimeManager::DeltaTime();
    if (Time[0] >= isDeadTime) {
        isDead = true;
    }
    Billboard();
}

void Bullet_Web::Render()
{
    Bullet::Render();
}

void Bullet_Web::OnCollision(GameObject* target)
{
    if (target->isAlliance == this->isAlliance) {
        return;
    }

    //if (dynamic_cast<Player*>(target)) {
       //몬스터와 충돌 이벤트
    //isDead = true;
    //}
}