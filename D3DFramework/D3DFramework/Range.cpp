#include "stdafx.h"
#include "Range.h"
#include "Rectangle.h"
#include "Player.h"
#include "Bullet.h"

Range::Range()
{   //TODO : 불렛이 지형타는중
    SetTexture(State::IDLE, TextureKey::RANGE, 1);
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

    moveSpeed = 0.f;
}

Range::~Range()
{
}

void Range::Update()
{

    Bullet::Update();

    /*transform->position += direction * moveSpeed * TimeManager::DeltaTime();;*/
    Time[0] += TimeManager::DeltaTime();
    if (Time[0] >= 2.f) {
        isDead = true;
    }
    Billboard();
}

void Range::Render()
{
    Bullet::Render();
}
